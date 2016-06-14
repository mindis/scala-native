#include <exception>
#include <cxxabi.h>
#include <gc.h>
#include <stdio.h>

namespace __cxxabiv1 {
extern "C" void *__cxa_begin_catch (void *);
extern "C" void __cxa_end_catch ();
}

namespace scalanative {
    class ExceptionWrapper: public std::exception {
    public:
        ExceptionWrapper(void* _obj): obj(_obj) { }
        void* obj;
    };
}

extern "C" {
    void scalanative_throw(void* obj) {
        throw new scalanative::ExceptionWrapper(obj);
    }

    void* scalanative_begin_catch(void* wrapper) {
        __cxxabiv1::__cxa_begin_catch(wrapper);
        return ((scalanative::ExceptionWrapper*) wrapper)->obj;
    }

    void scalanative_end_catch() {
        __cxxabiv1::__cxa_end_catch();
    }

    void* scalanative_alloc(void* info, size_t size) {
        void** alloc = (void**) GC_malloc(size);
        *alloc = info;
        return (void*) alloc;
    }

    void scalanative_init() {
        GC_init();
    }

    void* scalanative_libc_stderr() {
        return stderr;
    }

    void* scalanative_libc_stdout() {
        return stdout;
    }

    int scalanative_libc_eof() {
        return EOF;
    }

    unsigned int scalanative_libc_fopen_max() {
        return FOPEN_MAX;
    }

    unsigned int scalanative_libc_filename_max() {
        return FILENAME_MAX;
    }

    unsigned int scalanative_libc_bufsiz() {
        return BUFSIZ;
    }

    int scalanative_libc_iofbf() {
        return _IOFBF;
    }

    int scalanative_libc_iolbf() {
        return _IOLBF;
    }

    int scalanative_libc_ionbf() {
        return _IONBF;
    }

    int scalanative_libc_seek_set() {
        return SEEK_SET;
    }

    int scalanative_libc_seek_cur() {
        return SEEK_CUR;
    }

    int scalanative_libc_seek_end() {
        return SEEK_END;
    }

    unsigned int scalanative_tmp_max() {
        return TMP_MAX;
    }

    unsigned int scalanative_l_tmpnam() {
        return L_tmpnam;
    }
}


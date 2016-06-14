package scala.scalanative
package libc

import native._

@extern
object stdlib {

  // Memory management

  def malloc(size: CSize): Ptr[_] = extern
  def calloc(num: CSize, size: CSize): Ptr[_] = extern
  def realloc(ptr: Ptr[_], newSize: CSize): Ptr[_] = extern
  def free(ptr: Ptr[_]): Unit = extern

  // Program utilities

  def abort(): Unit = extern
  def exit(exitCode: CInt): Unit = extern
  def quick_exit(exitCode: CInt): Unit = extern
  def _Exit(exitCode: CInt): Unit = extern
  def atexit(func: FunctionPtr0[Unit]): CInt
  def at_quick_exit(func: FunctionPtr0[Unit]): CInt

  // Communicating with the environment

  def system(command: CString): CInt = extern
  def getenv(name: CString): CString = extern

  // Signals

  def signal(sig: CInt, handler: FunctionPtr1[CInt, Unit]): FunctionPtr1[CInt, Unit] = extern
  def raise(sig: CInt): CInt = extern

  // Types

  @struct class sig_atomic_t private ()
  @struct class jmp_buf private ()

  // Macros

  def EXIT_SUCCESS
  def EXIT_FAILURE
  def SIG_DFL
  def SIG_IGN
  def SIG_ERR
  def SIGABRT
  def SIGFPE
  def SIGILL
  def SIGINT
  def SIGSEGV
  def SIGTERM
}

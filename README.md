# CTF Pwn tasks
## name 200
* `alphanumeric shellcoding`.
## memo_manager 250
* PIE on, and full relro.
* Use input end without NULL byte weakness in printf to leak `PIE base`, stack address, and libc.
* Use vulnerability to do stack overflow.
* It could only overflow to return address for one gadget, you can use magic gadget in libc or do `stack migration` for `ret2libc`.
## final_countdown 300
* Advanced format string attack.
* All protection are enabled.
* `fmt` buf is at global.
* Because of full `relro`, you can't do `gothijacking`.
* First time `fmt` Leak stack address and libc base.
* Second time `fmt` to forge last two byte of `rbp`.
* Overwrite return address of `_IO_vfprintf_internal` with one gadget.
## Joke 350
* `_dl_make_stack_executable`.
* Socket shellcodeing.
* Reverse shell.
## Three pages 450
* `add_name` overflow overwrite top chunk size.
* House of force to overwrite data pointer.
* Leak libc and overwrite `__malloc_hook`.
* Leave messege trigger shell.
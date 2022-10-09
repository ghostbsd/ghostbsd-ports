This is the FreeBSD Ports Collection. For an easy to use
WEB-based interface to it, please see:

http://www.freebsd.org/ports

For general information on the Ports Collection, see [Installing Applications: Packages and Ports](https://docs.freebsd.org/en/books/handbook/ports/) in the FreeBSD Handbook, or the [ports(7)](https://www.freebsd.org/cgi/man.cgi?query=ports&sektion=7&manpath=FreeBSD) manual page (man ports). These will explain how to use ports and packages.

If you would like to search for a port, you can do so easily by
saying (in `/usr/ports`):


	make search name="<name>"
	or:
	make search key="<keyword>"

which will generate a list of all ports matching <name> or <keyword>.
make search also supports wildcards, such as:

	make search name="gtk*"

For information about contributing to FreeBSD ports, please see the Porter's
Handbook:

https://docs.freebsd.org/en/books/porters-handbook/

NOTE:  This tree will GROW significantly in size during normal usage!
The distribution tar files can and do accumulate in `/usr/ports/distfiles`,
and the individual ports will also use up lots of space in their work
subdirectories unless you remember to "make clean" after you're done
building a given port.  `/usr/ports/distfiles` can also be periodically
cleaned without ill-effect.


## Instructions for keeping GhostBSD ports current with FreeBSD ports.

https://github.com/ghostbsd/ghostbsd-ports/discussions/26#discussion-55695

## To use the hook from FreeBSD adapted for GhostBSD.

```
git config --add core.hooksPath .hooks
```

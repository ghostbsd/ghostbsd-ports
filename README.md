This repository combines: 

* the FreeBSD ports collection
* PkgBase-oriented GhostBSD ports.

The combination allows simplified, coherent updates to the (base) operating system and other installed software. 

For an easy-to-use web-based interface to the FreeBSD ports collection, please see [FreshPorts](https://www.freshports.org/). For more general information, see [Installing Applications: Packages and Ports](https://docs.freebsd.org/en/books/handbook/ports/) in the FreeBSD Handbook, or the [ports(7)](https://www.freebsd.org/cgi/man.cgi?query=ports&sektion=7&manpath=FreeBSD) manual page (man ports). These will explain how to use ports and packages.

If you would like to seek a port in your copy of this repo, you can do so easily. `cd` to the directory e.g. `/usr/ports`, then: 

    make search name="<name>"

– or:

    make search key="<keyword>"

– to generate a list of all ports matching `<name>` or `<keyword>`. 

`make search` also supports wildcards, such as:

    make search name="gtk*"

To seek available packages from the command line, options include [pkg-search(8)](https://www.freebsd.org/cgi/man.cgi?query=pkg-search&sektion=8&manpath=FreeBSD-Ports), for example: 

    pkg search -o pkg-provides

– and [pkg-rquery(8)](https://www.freebsd.org/cgi/man.cgi?query=pkg-rquery&sektion=8&manpath=FreeBSD-Ports), for example: 

    pkg rquery '%R %o %v\n\n%c\n\n%e' nano

For information about contributing to FreeBSD ports, see the [Porter's Handbook](https://docs.freebsd.org/en/books/porters-handbook/).

Note: the size of this tree **will grow** significantly through normal usage! Distribution files accumulate in `/usr/ports/distfiles` – this directory can be occasionally cleaned without ill-effect. Buliding ports will use much space in work subdirectories – when these work files are no longer required, you can `make clean`. 

### Instructions for keeping GhostBSD ports current with FreeBSD ports.

https://github.com/ghostbsd/ghostbsd-ports/discussions/26#discussion-55695

### To use the hook from FreeBSD adapted for GhostBSD.

```
git config --add core.hooksPath .hooks
```

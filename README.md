This is the FreeBSD Ports Collection.  For an easy to use
WEB-based interface to it, please see:

	http://www.FreeBSD.org/ports

For general information on the Ports Collection, please see the
FreeBSD Handbook ports section which is available from:

	http://www.FreeBSD.org/doc/en_US.ISO8859-1/books/handbook/ports.html
		for the latest official version
	or:
	The ports(7) manual page (man ports).

These will explain how to use ports and packages.

If you would like to search for a port, you can do so easily by
saying (in /usr/ports):


	make search name="<name>"
	or:
	make search key="<keyword>"

which will generate a list of all ports matching <name> or <keyword>.
make search also supports wildcards, such as:

	make search name="gtk*"

For information about contributing to FreeBSD ports, please see the Porter's
Handbook, available at:

	http://www.FreeBSD.org/doc/en_US.ISO8859-1/books/porters-handbook/

NOTE:  This tree will GROW significantly in size during normal usage!
The distribution tar files can and do accumulate in /usr/ports/distfiles,
and the individual ports will also use up lots of space in their work
subdirectories unless you remember to "make clean" after you're done
building a given port.  /usr/ports/distfiles can also be periodically
cleaned without ill-effect.


## Instructions for keeping GhostBSD ports current with FreeBSD ports.

To keep the GhostBSD ports tree current, we need to fetch and merge from the FreeBSD ports master. Sometimes we have some merge conflicts, and we need to fix them. Those conflicts may be related to svn, GhostBSD code, directories that have been renamed or removed that contain changes that were not in the original FreeBSD master branch.

Git always displays all the conflicts.

To fetch and merge from FreeBSD ports, we need to set the freebsd-ports remote repos to our local copy of ghostbsd-ports.

> git clone https://github.com/ghostbsd/ghostbsd-ports.git  

> cd ghostbsd 

> git remote add freebsd https://github.com/freebsd/freebsd-ports.git 

You should have this.

> git remote -v  
> freebsd    https://github.com/freebsd/freebsd-ports.git (fetch) 

> freebsd    https://github.com/freebsd/freebsd-ports.git (push) 

> origin    https://github.com/ghostbsd/ghostbsd-ports.git (fetch) 

> origin    https://github.com/ghostbsd/ghostbsd-ports.git (push 

To fetch from freebsd-ports.

> git fetch freebsd

To merge freebsd-ports master.

> git merge freebsd/master

If you don't have any conflict, you can push.

> git push origin master

If you have code conflicts, this is where the knowledge of maintaining ports comes to be necessary. When it is code related, it is not that hard. Most of the time is just a change that it was not able to do. For some reason, those are easy. When it comes to conflicts related to changes coming from us, we need to keep our code. The most common one is related to Mk files and Makefiles. FreeBSD does not contain the os ports, so merged that includes changes in Mk files that contain the code to recognize os ports will trigger a conflict.

Now code conflicts always get tagged in the code, so instead of reading the verbose, I grep everything like this:

> grep -R '<<<<<<< HEAD' *

It will give you all the files that have conflicts.

It has two tags in the code, the HEAD, which is our master and the freebsd/master. We need to fix conflicts, but to make sure we don't erase our own changes.

When all the conflicts are fixed, you need to add, commit and push.

> git add -A && git commit && git push origin master

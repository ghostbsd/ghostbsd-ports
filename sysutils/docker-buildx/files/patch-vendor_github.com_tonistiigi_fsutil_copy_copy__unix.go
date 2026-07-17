--- vendor/github.com/tonistiigi/fsutil/copy/copy_unix.go.orig	2026-07-06 12:19:07 UTC
+++ vendor/github.com/tonistiigi/fsutil/copy/copy_unix.go
@@ -62,7 +62,9 @@ func (c *copier) copyFileTimestamp(fi os.FileInfo, nam
 	}
 
 	st := fi.Sys().(*syscall.Stat_t)
-	timespec := []unix.Timespec{unix.Timespec(StatAtime(st)), unix.Timespec(StatMtime(st))}
+	atime := unix.Timespec{Sec: StatAtime(st).Sec, Nsec: StatAtime(st).Nsec}
+	mtime := unix.Timespec{Sec: StatMtime(st).Sec, Nsec: StatMtime(st).Nsec}
+	timespec := []unix.Timespec{atime, mtime}
 	if err := unix.UtimesNanoAt(unix.AT_FDCWD, name, timespec, unix.AT_SYMLINK_NOFOLLOW); err != nil {
 		return errors.Wrapf(err, "failed to utime %s", name)
 	}

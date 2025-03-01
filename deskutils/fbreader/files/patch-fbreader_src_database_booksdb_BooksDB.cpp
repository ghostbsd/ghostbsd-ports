--- fbreader/src/database/booksdb/BooksDB.cpp.orig	2014-01-11 12:45:25 UTC
+++ fbreader/src/database/booksdb/BooksDB.cpp
@@ -145,7 +145,7 @@ shared_ptr<Book> BooksDB::loadBook(const std::string &
 
 	myFindFileId->setFileName(fileName);
 	if (!myFindFileId->run()) {
-		return false;
+		return 0;
 	}
 	((DBIntValue&)*myLoadBook->parameter("@file_id").value()) = myFindFileId->fileId();
 	shared_ptr<DBDataReader> reader = myLoadBook->executeReader();

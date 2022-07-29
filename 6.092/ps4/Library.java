public class Library {
// Add the missing implementation to this class
	String address;
	Book[] books;
	int numbooks;

	public static void printOpeningHours() {
		System.out.println("Libraries are open daily from 9am to 5pm.");
	}

	Library(String location) {
		address = location;
		books = new Book[10];
		numbooks = 0;
	}

	public void printAddress() {
		System.out.println(address);
	}

	public void addBook(Book b) {
		books[numbooks] = b;
		numbooks += 1;
	}

	public void borrowBook(String s) {
		int flag = 0;
		for (int i = 0; i < numbooks; i++) {
			if (books[i].getTitle() == s) {
				flag = 1;
				if (!books[i].isBorrowed()) {
					flag = 2;
					books[i].borrowed();
				}
			}
		}
		if (flag == 0) {
			System.out.println("Sorry, this book is not in our catalog.");
		} else if (flag == 1) {
			System.out.println("Sorry, this book is already borrowed.");
		} else {
			System.out.println("You have successfully borrowed " + s);
		}
	}

	public void returnBook(String s) {
		int flag = 0;
		for (int i = 0; i < numbooks; i++) {
			if (books[i].getTitle() == s) {
				flag = 1;
				if (books[i].isBorrowed()) {
					flag = 2;
					books[i].returned();
				}
			}
		}
		if (flag == 0) {
			System.out.println("Sorry, this book is not in our catalog.");
		} else if (flag == 1) {
			System.out.println("Sorry, this book already exists in our catalog.");
		} else {
			System.out.println("You have successfully returned " + s);
		}
	}

	public void printAvailableBooks() {
		if (numbooks == 0)
			System.out.println("No book in catalog. ");
		for (int i = 0; i < numbooks; i++)
			if (!books[i].isBorrowed())
				System.out.println(books[i].getTitle());
	}

	public static void main(String[] args) {
// Create two libraries
		Library firstLibrary = new Library("10 Main St.");
		Library secondLibrary = new Library("228 Liberty St.");
// Add four books to the first library
		firstLibrary.addBook(new Book("The Da Vinci Code"));
		firstLibrary.addBook(new Book("Le Petit Prince"));
		firstLibrary.addBook(new Book("A Tale of Two Cities"));
		firstLibrary.addBook(new Book("The Lord of the Rings"));
// Print opening hours and the addresses
		System.out.println("Library hours:");
		printOpeningHours();
		System.out.println();
		System.out.println("Library addresses:");
		firstLibrary.printAddress();
		secondLibrary.printAddress();
		System.out.println();
// Try to borrow The Lords of the Rings from both libraries
		System.out.println("Borrowing The Lord of the Rings:");
		firstLibrary.borrowBook("The Lord of the Rings");
		firstLibrary.borrowBook("The Lord of the Rings");
		secondLibrary.borrowBook("The Lord of the Rings");
		System.out.println();
// Print the titles of all available books from both libraries
		System.out.println("Books available in the first library:");
		firstLibrary.printAvailableBooks();
		System.out.println();
		System.out.println("Books available in the second library:");
		secondLibrary.printAvailableBooks();
		System.out.println();
// Return The Lords of the Rings to the first library
		System.out.println("Returning The Lord of the Rings:");
		firstLibrary.returnBook("The Lord of the Rings");
		System.out.println();
// Print the titles of available from the first library
		System.out.println("Books available in the first library:");
		firstLibrary.printAvailableBooks();
	}
}
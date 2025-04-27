import java.util.ArrayList;
import java.util.Scanner;

class Instructor {
    private String name;
    private String phoneNumber;

    public Instructor() {
        this.name = "";
        this.phoneNumber = "";
    }

    public Instructor(String name, String phoneNumber) {
        this.name = name;
        this.phoneNumber = phoneNumber;
    }

    public void setName(String name) {
        this.name = name;
    }

    public void setPhoneNumber(String phoneNumber) {
        this.phoneNumber = phoneNumber;
    }

    public void setInstructorInfo(String name, String phoneNumber) {
        this.name = name;
        this.phoneNumber = phoneNumber;
    }

    public String getName() {
        return name;
    }

    public String getPhoneNumber() {
        return phoneNumber;
    }

    public void viewInformation() {
        System.out.println("Instructor Information:");
        System.out.println("Name: " + name);
        System.out.println("Phone Number: " + phoneNumber);
    }
}

class Textbook {
    private String title;
    private String authorName;
    private String publisher;

    public Textbook() {
        this.title = "";
        this.authorName = "";
        this.publisher = "";
    }

    public Textbook(String title, String authorName, String publisher) {
        this.title = title;
        this.authorName = authorName;
        this.publisher = publisher;
    }

    public void setTitle(String title) {
        this.title = title;
    }

    public void setAuthorName(String authorName) {
        this.authorName = authorName;
    }

    public void setPublisher(String publisher) {
        this.publisher = publisher;
    }

    public void setTextbookData(String title, String authorName, String publisher) {
        this.title = title;
        this.authorName = authorName;
        this.publisher = publisher;
    }

    public String getTitle() {
        return title;
    }

    public String getAuthorName() {
        return authorName;
    }

    public String getPublisher() {
        return publisher;
    }

    public void viewInformation() {
        System.out.println("Textbook Information:");
        System.out.println("Title: " + title);
        System.out.println("Author: " + authorName);
        System.out.println("Publisher: " + publisher);
    }
}

class Course {
    private String courseName;
    private Instructor instructor;
    private Textbook textbook;

    public Course() {
        this.courseName = "";
        this.instructor = new Instructor();
        this.textbook = new Textbook();
    }

    public Course(String courseName, Instructor instructor, Textbook textbook) {
        this.courseName = courseName;
        this.instructor = instructor;
        this.textbook = textbook;
    }

    public void setCourseName(String courseName) {
        this.courseName = courseName;
    }

    public void setInstructor(Instructor instructor) {
        this.instructor = instructor;
    }

    public void setTextbook(Textbook textbook) {
        this.textbook = textbook;
    }

    public String getCourseName() {
        return courseName;
    }

    public Instructor getInstructor() {
        return instructor;
    }

    public Textbook getTextbook() {
        return textbook;
    }

    public void viewInformation() {
        System.out.println("\n==== Course Information ====");
        System.out.println("Course Name: " + courseName);
        System.out.println("\n--- Instructor Details ---");
        instructor.viewInformation();
        System.out.println("\n--- Textbook Details ---");
        textbook.viewInformation();
        System.out.println("==========================\n");
    }
}

public class UniversityProgram {
    private static Scanner scanner = new Scanner(System.in);
    private static ArrayList<Instructor> instructors = new ArrayList<>();
    private static ArrayList<Textbook> textbooks = new ArrayList<>();
    private static ArrayList<Course> courses = new ArrayList<>();

    public static void main(String[] args) {
        boolean exit = false;

        while (!exit) {
            displayMainMenu();
            int choice = getIntInput("Enter your choice: ");

            switch (choice) {
                case 1:
                    instructorMenu();
                    break;
                case 2:
                    textbookMenu();
                    break;
                case 3:
                    courseMenu();
                    break;
                case 4:
                    System.out.println("Exiting program. Goodbye!");
                    exit = true;
                    break;
                default:
                    System.out.println("Invalid choice. Please try again.");
            }
        }

        scanner.close();
    }

    private static void displayMainMenu() {
        System.out.println("\n===== BCSE Program Management System =====");
        System.out.println("1. Instructor Management");
        System.out.println("2. Textbook Management");
        System.out.println("3. Course Management");
        System.out.println("4. Exit");
        System.out.println("========================================");
    }

    private static void instructorMenu() {
        boolean back = false;

        while (!back) {
            System.out.println("\n===== Instructor Management =====");
            System.out.println("1. Add New Instructor");
            System.out.println("2. View All Instructors");
            System.out.println("3. Update Instructor Information");
            System.out.println("4. Back to Main Menu");
            System.out.println("===============================");

            int choice = getIntInput("Enter your choice: ");

            switch (choice) {
                case 1:
                    addInstructor();
                    break;
                case 2:
                    viewAllInstructors();
                    break;
                case 3:
                    updateInstructor();
                    break;
                case 4:
                    back = true;
                    break;
                default:
                    System.out.println("Invalid choice. Please try again.");
            }
        }
    }

    private static void textbookMenu() {
        boolean back = false;

        while (!back) {
            System.out.println("\n===== Textbook Management =====");
            System.out.println("1. Add New Textbook");
            System.out.println("2. View All Textbooks");
            System.out.println("3. Update Textbook Information");
            System.out.println("4. Back to Main Menu");
            System.out.println("=============================");

            int choice = getIntInput("Enter your choice: ");

            switch (choice) {
                case 1:
                    addTextbook();
                    break;
                case 2:
                    viewAllTextbooks();
                    break;
                case 3:
                    updateTextbook();
                    break;
                case 4:
                    back = true;
                    break;
                default:
                    System.out.println("Invalid choice. Please try again.");
            }
        }
    }

    private static void courseMenu() {
        boolean back = false;

        while (!back) {
            System.out.println("\n===== Course Management =====");
            System.out.println("1. Add New Course");
            System.out.println("2. View All Courses");
            System.out.println("3. Update Course Information");
            System.out.println("4. Back to Main Menu");
            System.out.println("===========================");

            int choice = getIntInput("Enter your choice: ");

            switch (choice) {
                case 1:
                    addCourse();
                    break;
                case 2:
                    viewAllCourses();
                    break;
                case 3:
                    updateCourse();
                    break;
                case 4:
                    back = true;
                    break;
                default:
                    System.out.println("Invalid choice. Please try again.");
            }
        }
    }

    private static void addInstructor() {
        System.out.println("\n--- Add New Instructor ---");

        System.out.print("Enter instructor name: ");
        String name = scanner.nextLine();

        System.out.print("Enter phone number: ");
        String phoneNumber = scanner.nextLine();

        Instructor instructor = new Instructor(name, phoneNumber);
        instructors.add(instructor);

        System.out.println("Instructor added successfully!");
    }

    private static void viewAllInstructors() {
        System.out.println("\n--- All Instructors ---");

        if (instructors.isEmpty()) {
            System.out.println("No instructors available.");
            return;
        }

        for (int i = 0; i < instructors.size(); i++) {
            System.out.println("\nInstructor #" + (i + 1));
            instructors.get(i).viewInformation();
        }
    }

    private static void updateInstructor() {
        if (instructors.isEmpty()) {
            System.out.println("No instructors available to update.");
            return;
        }

        System.out.println("\n--- Update Instructor Information ---");
        viewAllInstructors();

        int index = getIntInput("Enter the instructor number to update (1-" + instructors.size() + "): ") - 1;

        if (index < 0 || index >= instructors.size()) {
            System.out.println("Invalid instructor number.");
            return;
        }

        System.out.print("Enter new name (or press Enter to keep current): ");
        String name = scanner.nextLine();
        if (!name.isEmpty()) {
            instructors.get(index).setName(name);
        }

        System.out.print("Enter new phone number (or press Enter to keep current): ");
        String phoneNumber = scanner.nextLine();
        if (!phoneNumber.isEmpty()) {
            instructors.get(index).setPhoneNumber(phoneNumber);
        }

        System.out.println("Instructor information updated successfully!");
    }

    private static void addTextbook() {
        System.out.println("\n--- Add New Textbook ---");

        System.out.print("Enter textbook title: ");
        String title = scanner.nextLine();

        System.out.print("Enter author name: ");
        String authorName = scanner.nextLine();

        System.out.print("Enter publisher: ");
        String publisher = scanner.nextLine();

        Textbook textbook = new Textbook(title, authorName, publisher);
        textbooks.add(textbook);

        System.out.println("Textbook added successfully!");
    }

    private static void viewAllTextbooks() {
        System.out.println("\n--- All Textbooks ---");

        if (textbooks.isEmpty()) {
            System.out.println("No textbooks available.");
            return;
        }

        for (int i = 0; i < textbooks.size(); i++) {
            System.out.println("\nTextbook #" + (i + 1));
            textbooks.get(i).viewInformation();
        }
    }

    private static void updateTextbook() {
        if (textbooks.isEmpty()) {
            System.out.println("No textbooks available to update.");
            return;
        }

        System.out.println("\n--- Update Textbook Information ---");
        viewAllTextbooks();

        int index = getIntInput("Enter the textbook number to update (1-" + textbooks.size() + "): ") - 1;

        if (index < 0 || index >= textbooks.size()) {
            System.out.println("Invalid textbook number.");
            return;
        }

        System.out.print("Enter new title (or press Enter to keep current): ");
        String title = scanner.nextLine();
        if (!title.isEmpty()) {
            textbooks.get(index).setTitle(title);
        }

        System.out.print("Enter new author name (or press Enter to keep current): ");
        String authorName = scanner.nextLine();
        if (!authorName.isEmpty()) {
            textbooks.get(index).setAuthorName(authorName);
        }

        System.out.print("Enter new publisher (or press Enter to keep current): ");
        String publisher = scanner.nextLine();
        if (!publisher.isEmpty()) {
            textbooks.get(index).setPublisher(publisher);
        }

        System.out.println("Textbook information updated successfully!");
    }

    private static void addCourse() {
        if (instructors.isEmpty() || textbooks.isEmpty()) {
            System.out.println("Cannot add a course without instructors and textbooks.");
            System.out.println("Please add at least one instructor and one textbook first.");
            return;
        }

        System.out.println("\n--- Add New Course ---");

        System.out.print("Enter course name: ");
        String courseName = scanner.nextLine();

        viewAllInstructors();
        int instructorIndex = getIntInput("Select instructor number (1-" + instructors.size() + "): ") - 1;

        if (instructorIndex < 0 || instructorIndex >= instructors.size()) {
            System.out.println("Invalid instructor selection. Course not added.");
            return;
        }

        viewAllTextbooks();
        int textbookIndex = getIntInput("Select textbook number (1-" + textbooks.size() + "): ") - 1;

        if (textbookIndex < 0 || textbookIndex >= textbooks.size()) {
            System.out.println("Invalid textbook selection. Course not added.");
            return;
        }

        Course course = new Course(courseName, instructors.get(instructorIndex), textbooks.get(textbookIndex));
        courses.add(course);

        System.out.println("Course added successfully!");
    }

    private static void viewAllCourses() {
        System.out.println("\n--- All Courses ---");

        if (courses.isEmpty()) {
            System.out.println("No courses available.");
            return;
        }

        for (int i = 0; i < courses.size(); i++) {
            System.out.println("\nCourse #" + (i + 1));
            courses.get(i).viewInformation();
        }
    }

    private static void updateCourse() {
        if (courses.isEmpty()) {
            System.out.println("No courses available to update.");
            return;
        }

        System.out.println("\n--- Update Course Information ---");
        viewAllCourses();

        int index = getIntInput("Enter the course number to update (1-" + courses.size() + "): ") - 1;

        if (index < 0 || index >= courses.size()) {
            System.out.println("Invalid course number.");
            return;
        }

        System.out.print("Enter new course name (or press Enter to keep current): ");
        String courseName = scanner.nextLine();
        if (!courseName.isEmpty()) {
            courses.get(index).setCourseName(courseName);
        }

        System.out.print("Do you want to change the instructor? (y/n): ");
        String changeInstructor = scanner.nextLine().toLowerCase();

        if (changeInstructor.equals("y")) {
            viewAllInstructors();
            int instructorIndex = getIntInput("Select new instructor number (1-" + instructors.size() + "): ") - 1;

            if (instructorIndex >= 0 && instructorIndex < instructors.size()) {
                courses.get(index).setInstructor(instructors.get(instructorIndex));
            } else {
                System.out.println("Invalid instructor selection. Instructor not changed.");
            }
        }

        System.out.print("Do you want to change the textbook? (y/n): ");
        String changeTextbook = scanner.nextLine().toLowerCase();

        if (changeTextbook.equals("y")) {
            viewAllTextbooks();
            int textbookIndex = getIntInput("Select new textbook number (1-" + textbooks.size() + "): ") - 1;

            if (textbookIndex >= 0 && textbookIndex < textbooks.size()) {
                courses.get(index).setTextbook(textbooks.get(textbookIndex));
            } else {
                System.out.println("Invalid textbook selection. Textbook not changed.");
            }
        }

        System.out.println("Course information updated successfully!");
    }

    private static int getIntInput(String prompt) {
        int input = 0;
        boolean validInput = false;

        while (!validInput) {
            try {
                System.out.print(prompt);
                input = scanner.nextInt();
                validInput = true;
            } catch (Exception e) {
                System.out.println("Invalid input. Please enter a number.");
            }
        }

        return input;
    }
}
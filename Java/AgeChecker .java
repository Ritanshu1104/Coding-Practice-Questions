public class Age1 {
    public static void checkAge(int age) {
        if (age >= 18) {
            System.out.println("You can vote");
        } else {
            System.out.println("No sorry, you are not eligible");
        }
    }
}

public class AgeChecker {
    public static void main(String[] args) {
        Age1.checkAge(20);  // Example age passed here
    }
}

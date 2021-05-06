import java.util.Scanner;

class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        System.out.print("Input n: ");
        int n = scanner.nextInt();
        scanner.close();

        System.out.println(n + " / 2 = " + n / 2 + " (Int)");
    }
}
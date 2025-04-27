import java.util.Scanner;

public class SumOfEvensInCLinkedList {
    static class ListNode {
        int value;
        ListNode next;

        public ListNode(int value) {
            this.value = value;
            this.next = null;
        }
    }

    public static ListNode createCircularLinkedList(int size) {
        ListNode head = null, temp = null;
        System.out.print("Enter values of the list: ");
        Scanner sc = new Scanner(System.in);
        for (int i = 0; i < size; i++) {
            int n = sc.nextInt();
            ListNode newNode = new ListNode(n);
            if (head == null) {
                head = newNode;
                temp = head;
            } else {
                temp.next = newNode;
                temp = temp.next;
            }
        }
        if (temp != null) {
            temp.next = head;
        }
        sc.close();
        return head;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter Size of the List: ");
        int size = sc.nextInt();

        ListNode mynde = createCircularLinkedList(size);
        System.out.println("Sum of all even numbers in list is: " + sumOfAllEvenNumbers(mynde));
        sc.close();
    }

    public static int sumOfAllEvenNumbers(ListNode list) {
        if (list == null) {
            return 0;
        }

        ListNode temp = list;
        int sum = 0;

        do {
            if (temp.value % 2 == 0) {
                sum += temp.value;
            }
            temp = temp.next;
        } while (temp != list);

        return sum;
    }
}
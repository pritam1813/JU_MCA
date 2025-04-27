import java.util.*;

public class RootToLeafPaths {
    public static void main(String[] args) {
        List<String> btree = new ArrayList<String>();
        btree.add("1");
        btree.add("2");
        btree.add("3");
        btree.add(null);
        btree.add("5");
        btree.add("4");

        List<String> arr = new ArrayList<String>();
        traveseBinaryTree(btree, 0, arr);
    }

    public static void traveseBinaryTree(List<String> root, int index, List<String> arr) {
        if (root.get(index) == null || index > root.size()) {
            return;
        }

        arr.add(root.get(index));

        int leftIndex = (2 * index) + 1;
        int rightIndex = (2 * index) + 2;

        if (leftIndex > root.size() || root.get(leftIndex) == null || rightIndex > root.size()
                || root.get(rightIndex) == null) {
            return;
        } else {
            traveseBinaryTree(root, leftIndex, arr);
            traveseBinaryTree(root, rightIndex, arr);
        }

        // return;
    }
}

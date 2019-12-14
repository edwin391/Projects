public class arrays {
    public static void main(String[] args) {
        int testing[] = {1,3,4,7,6};
        for (int i = 0; i<testing.length; i++) {
            if (testing[i] == 7) {
                System.out.println(i);
            }
            else{
                System.out.println("no");
            }
        }

    }
}

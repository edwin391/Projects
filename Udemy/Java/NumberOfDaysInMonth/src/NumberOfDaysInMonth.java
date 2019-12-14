public class NumberOfDaysInMonth {

    public static boolean isLeapYear(int year) {

        if(year < 1 || year > 9999) {
            return false;
        } else if(year % 4 == 0) {
            if(year % 100 == 0){
                if(year % 400 == 0) {
                    return true;
                } else {
                    return false;
                }
            } else {
                return true;
            }
        } else {
            return false;
        }
    }

    public static int getDaysInMonth(int month, int year) {

        int days = 0;
        if(month < 1 || month > 12 || year < 1 || year > 9999) {
            //System.out.println("-1");
            return -1;
        } else {
            //isLeapYear(year);
            switch(month) {
                case 1: case 3: case 5: case 7: case 8: case 10: case 12:
                    //System.out.println("31");
                    days = 31;
                    break;
                case 2:
                    if (isLeapYear(year) == true) {
                        //System.out.println("29");
                        days = 29;
                        //return 29;
                    } else {
                        //System.out.println("28");
                        days = 28;
                        //return 28;
                    }
                    break;
                case 4: case 6: case 9: case 11:
                    days = 30;
                    //System.out.println("30");
                    //return 30;
                    break;
                default:
                    //System.out.println("-1");
                    //return -1;
                    break;

            }
            return days;
        }
    }
}

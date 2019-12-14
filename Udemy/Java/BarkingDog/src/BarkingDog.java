public class BarkingDog {

    public static boolean shouldWakeUp(boolean barking, int hourOfDay){
        if(barking && hourOfDay >= 0 && hourOfDay < 8 || barking && hourOfDay > 22 && hourOfDay <=23) {
            return true;
        } else
            return false;
    }
}

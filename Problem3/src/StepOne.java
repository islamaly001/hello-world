import java.security.SecureRandom;

import java.util.Scanner;



public class StepOne

{

    public static int askQ(){

        SecureRandom rand = new SecureRandom();

        int rand_int1 = rand.nextInt(10);

        int rand_int2 = rand.nextInt(10);



        System.out.println("How much is "+ rand_int1+  " times "+rand_int2+  "?");

        return rand_int1*rand_int2;

    }



    public static void main(String args[])

    {



        Scanner sc = new Scanner(System.in);

        int userNum,num;

        num = askQ();

        while(true){

            userNum = sc.nextInt();

            if(userNum==num){

                System.out.println("Very good!");

                num = askQ();

            }else{

                System.out.println("No. Please try again.");

            }

        }

    }



}

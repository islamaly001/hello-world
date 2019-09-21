package aly_p3;
import java.util.Scanner;
public class Aly_p3 {

	static String[] s={"Food","Video games","Soccer","School","Graduation"};
	static int[][] f=new int[5][10];
	public static void main(String[] args){
	   double[] sum=new double[]{0,0,0,0,0};
	   double avg=0;
	   Scanner inp=new Scanner(System.in);
	   for(int i=0;i<10;i++){
	       for(int j=0;j<5;j++){
	           System.out.println("Give your Rating between 1-10 for the Issue\n"+(j+1)+"."+s[j]);
	           f[j][i]=inp.nextInt();
	       }
	   }
	   System.out.println("Responses");
	   for(int i=0;i<5;i++){
	       System.out.print("\n"+(i+1)+"."+s[i]);
	       for(int j=0;j<10;j++){
	           System.out.print(f[i][j]+"\t");
	           sum[i]=sum[i]+f[i][j];
	       }
	       avg=sum[i]/10;
	       System.out.print("Average = "+avg);
	   }
	   double max=sum[0],min=sum[0];
	   int maxI=0,minI=0;
	   for(int i=0;i<5;i++){
	       if(max<sum[i]){
	           max=sum[i];
	           maxI=i;
	       }
	       if(min>sum[0]){
	           min=sum[0];
	           minI=i;
	       }
	   }
	   System.out.println("MaximumRated Issue "+s[maxI]+"\tRatings:"+max);
	   System.out.println("Minimum rated Issue "+s[minI]+"\tRatings"+min);
	   inp.close();
	   }

	  
	}


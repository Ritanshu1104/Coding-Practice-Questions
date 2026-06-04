public class armstrong
{
 public static void main(String[]args)
 {
  System.out.println("Armstrong Number between 1 - 1000: ");
  for(int i=1;i<=1000;i++)
  {
   int orinum=i;
   int sum=0;
   int temp=i;
   int digits=0;

   while(temp!=0)
   {
    digits++;
    temp/=10;
   }
    temp=i;
    while(temp!=0)
    { 
	int rem=temp%10;
	int power = 1;
	for (int j=0;j<digits;j++)
	{
 	  power*=rem;
	}
	  sum+=power;
	  temp/=10;
    }
	if(sum==orinum)
	{ 
 	  System.out.println(orinum);
	}
  }
 }
}
#include<stdio.h>
int n;
struct processes
{

int processno;

int arrivaltime,cpuburst_t,ct,waitingtime,turnaroundt,p;

int flags;
 }plist[100];
 void sorting()
 {
struct processes p;

int x, y;

for(x=0;x<n-1;x++)

{

for(y=x+1;y<n;y++)

{

if(plist[x].arrivaltime > plist[y].arrivaltime)

{

p = plist[x];

plist[x] = plist[y];

plist[y] = p;

}

}

}
 }
 int main()
 {

int x,t=0,bt=0,peaks;

int a[10];

float waittime = 0, turnaroundt = 0, avgwt=0, avgtat=0;

printf("Enter the No. of Processes: ");

scanf("%d",&n);

for(x = 0; x < n; x++)

{

plist[x].processno = x+1;

printf("\nEnter Details For P%d processes:-\n", plist[x].processno);
printf("Enter Arrival Time of the Processes: ");
scanf("%d", &plist[x].arrivaltime );
printf("Enter Burst Time of the Processes: ");
scanf("%d", &plist[x].cpuburst_t);
plist[x].flags = 0;
bt = bt + plist[x].cpuburst_t;
}
sorting();
for(int x=0;x<n;x++)
{
a[x]=plist[x].cpuburst_t;
}
plist[9].cpuburst_t = 9999;
for(t = plist[0].arrivaltime; t <= bt+1;)
{
peaks = 9;
for(x=0;x<n;x++)
{
if(plist[x].arrivaltime <= t && plist[x].cpuburst_t < plist[peaks].cpuburst_t && plist[x].flags != 1)
{
peaks = x;
}
if(plist[peaks].cpuburst_t==0 && plist[x].flags != 1)
{
plist[x].flags = 1;
plist[peaks].ct=t;plist[peaks].cpuburst_t=9999;
printf("P%d Completes in %d\n",plist[x].processno,plist[peaks].ct);
}
}
t++;
(plist[peaks].cpuburst_t)--;
}
for(x=0;x<n;x++)
{
plist[x].turnaroundt=(plist[x].ct)-(plist[x].arrivaltime);
avgtat=avgtat+plist[x].turnaroundt;
plist[x].waitingtime=((plist[x].turnaroundt)-a[x]);
avgwt=avgwt+plist[x].waitingtime;
}
printf("P.NO\tA.T\tC.T\tT.A\tW.Tt\n");
for(x=0;x<n;x++)
{
printf("P%d\t%d\t%d\t%d\t%d\n",plist[x].processno,plist[x].arrivaltime,plist[x].ct,plist[x].turnaroundt
,plist[x].waitingtime);
 }
printf("Average Turn around Time  Of The Processes: %f\t\n\n",avgtat);
printf("Average Waiting Time  Of The Processes :\t %f\t\n",avgwt);
}

class Solution {
public:
    int getdays(string dates){
       int day[20] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
       int month = (dates[0]-'0')*10 + dates[1]-'0';
       int date = (dates[3]-'0')*10 + dates[4]-'0';
       int days = date;
       for(int i=0;i<month-1;i++){
        days+=day[i];
       }
       return days;
       
    }
    int countDaysTogether(string arriveAlice, string leaveAlice, string arriveBob, string leaveBob) {
      int firstarr = getdays(arriveAlice);
      int firstdep = getdays(leaveAlice);
      int secondarr = getdays(arriveBob);
      int seconddep = getdays(leaveBob);
      int arr = max(firstarr,secondarr);
      int dep = min(firstdep,seconddep);
      return dep<arr?0:dep-arr+1;

    }
};
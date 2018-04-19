// 0: Sunday
int whatday(int year, int month, int day)
{
	int y=year%100, c=year/100, d=day;
	int m=month+(month<=2?12:0);
	return (y+y/4+c/4-2*c+(26*(m+1)/10)+d-1+7)%7;
}
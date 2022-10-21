#include <iostream>
#include <cstdio>
# include <cstdlib>
using namespace std;

int main() {
	int i, p, z, c[101]={0};
	string stand[101], edit[101], edit2[101];
	cin >> i >> stand[0];
	string a[101];
	int target[101]={0};

	for (int x = 1; x <= i; x++) {
		cin >> p;
		getchar();
		getline(cin, a[x]);
		switch (p) {
			case 1:
				stand[x] = stand[x-1] + a[x];
				break;
			case 2:
				for (int q = a[x][0] - '0'; q <= (a[x][0]-'0') + (a[x][2] - '0') - 1; q++) {
					edit[x] += stand[x-1][q];
				}
				stand[x] = edit[x];
				break;
			case 3:
				edit[x] = "";
				z = a[x][0]-'0';
				for(int q=2;q<=a[x].length()-1;q++){
					edit[x]+=a[x][q];
				}
				for(int q =0;q<=z-1;q++)
					edit2[x] += stand[x-1][q];
				edit[x]=edit2[x]+edit[x];
				for(int q=z;q<=stand[x-1].length()-1;q++)
					edit[x] += stand[x-1][q];
				stand[x] = edit[x];
				break;
			case 4:
				target[x]=1;
				stand[x]=stand[x-1];
				for(int q=0;q<=stand[x-1].length()-1;q++){
					if(stand[x-1][q]==a[x][0]){
						for(int s=0;s<=a[x].length()-1;s++){
							if(stand[x-1][q+s]!=a[x][s]){
								break;
							}else if(s==a[x].length()-2)
								c[x]+=1;
				break;			
						}
					}
				}
		}
	}

 
	for(int x=1;x<=i;x++){
		if(target[x]==1)
			if(c[x]==0)
				cout<<-1<<endl;
			else
				cout<<c[x]<<endl;
		else
			cout<<stand[x]<<endl;
	}
}

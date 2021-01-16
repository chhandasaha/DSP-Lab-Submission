#include<stdio.h>
void towerOfHanoi(int disk_count, char source_rod, char destination_rod, char spare_rod){
	if(disk_count == 1){
		printf("\nMove disk 1 from source rod %c to destination rod %c", source_rod, destination_rod);
		return;
	}
	else{
		towerOfHanoi(disk_count-1, source_rod,  spare_rod, destination_rod);
		printf("\nMove %d disk from source rod %c to destination rod %c", disk_count, source_rod, destination_rod);
		towerOfHanoi(disk_count-1, spare_rod, destination_rod, spare_rod);	
	}
}
int main(){
	int disk_count;
	printf("\nEnter number of disk : ");
	scanf("%d", &disk_count);
	towerOfHanoi(disk_count, 'A','B','C');
	return 0;
}

#include <stdio.h>

int main(){
	//inisialisasi
	int data[100];
	int i,n,j,tmp;
	int hasil,angkadicari;
	
	printf("------------------------------------------------- \n");
	printf("|   PROGRAM MENCARI ANGKA DENGAN SEARCH BINARY   | \n");
    printf("------------------------------------------------- \n\n");
	
	//memasukkan jumlah data oleh pengguna
	printf("Masukkan banyak data : "); scanf("%d", &n);
	
	//memasukkan angka
    for(i=0; i<n; i++)
    {
        printf("Data %d = ", i); scanf("%d", &data[i]);
    }
	
	//menampilkan angka sebelum diurutkan
	printf("--- Data Sebelum Diurutkan --- \n");
	for(i=0;i<n;i++){
		printf("%d", data[i]);
		printf("\n");
	}
	
	printf("\n");
	printf("\n");
	printf("--- Data Setelah Diurutkan --- \n");
	
	//sorting
	for(i=0;i<n-1;i++){
		
		for (j=i+1;j<=n;j++){
		
			if(data[i]>data[j])
			{
				tmp=data[i];
				data[i]=data[j];
				data[j]=tmp;
			}
		}
	
	}
		
	//menampilkan data setelah diurutkan	
	for(i=0;i<n;i++){
		printf("%d \n", data[i]);
	}
	
	//memasukkan angka yang ingin dicari
	printf("Masukkan angka yang dicari : "); scanf("%d", &angkadicari);
	
    hasil = biner ( angkadicari , n ,data);

    if  ( hasil == - 1 )
    {
        printf("\nData tidak ditemukan !! ");
    }
    else
    {
        printf("\nAngka %d ditemukan di indeks %d", angkadicari ,hasil);
    }
	return 0;	
}



//fungsi untuk mencari angka dengan pencarian bagi dua
int biner ( int cari ,int n , int angka[])
{
    //variable untuk menentukan titik awal ,akhir nya
    int akhir ,awal ,tengah ,ketemu , i;
   
    akhir = n - 1; awal = 0; ketemu = -1; i = 0;
    //Perulangan untuk mencari angka nya dengan kondisi ketemu = -1 dan i < n
    while ( ketemu == -1 && i < n )
    {  
        tengah = ( awal+ akhir ) / 2;
            /**
             *Perkondisian data yang ditengah = cari / ketemu dan pencarian dihentikan karena  ketemu = tengah bukan ketemu = -1 jadi tidak memenuhi                                          syarat untuk perulangan lagi 
             *dan ketemu = tengah , jadi nilai yang dikembalikan ke main  nanti adalah   indeks ke - tengah / indeks tempat data yang dicari ditemuakn
            **/
            if ( angka[tengah] == cari )
        {
            ketemu = tengah;
        }
        else
        {
            if ( angka[tengah] < cari )
            {
                awal = tengah + 1;
            }
            else
            {
                akhir = tengah - 1;
            }
        }i++;
    }
	
	return ketemu;
}











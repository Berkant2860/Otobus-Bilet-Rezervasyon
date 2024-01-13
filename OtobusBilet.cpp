/* BERKANT UZUN 2112721036 - OTOBUS BILET REZERVASYON SISTEMI */
#include<iomanip>
#include<cstring>
#include<stdlib.h>
#include<conio.h>
#include<fstream>
#include<iostream>

using namespace std;

struct bilgiler
{
	char ad[20];
	char soyad[30];
	char sube;
	string TC;
	char cinsiyet;
	int yas;
} ;
int main() 
{
	setlocale(LC_ALL,"Turkish");
	char secim;
    char degisiklik;
    int sec;
    char f, c,kayit,l,a,b;

	bilgiler yolcu;
    
	do
	{
		{
		//binary dosyaya yazmak
	    ofstream veri("otobus.dat");	   
	    cout<<"\n *********************************************************"<<endl;
		cout<<" *____________ [-OTOBUS BILET REZERVASYON SÝSTEMÝ-] ____________* "<<endl;
		cout<<" *                      HOÞGELDÝNÝZ                      * "<<endl;
	    cout<<" *********************************************************"<<endl; 
		cout<<" __________________________________________________________"<<endl;	    
	   	
		do
		{
			cout<<"-------------------------------------------------------------"<<endl;
			cout<<"\n Yolcunun T.C Kimlik Numarasýný giriniz  : ";
	    	cin>>yolcu.TC;
			cout<<"\n Yolcunun adýný giriniz  : ";
		    cin>>yolcu.ad;
		    cout<<"\n Yolcunun soyadýný giriniz  : ";
		    cin>>yolcu.soyad;
	    	cout<<"\n Yolcunun cinsiyetini giriniz  [E/K] : ";
       		cin>>yolcu.cinsiyet;
     		cout<<"\n Yolcunun Yaþýný Giriniz  : ";
     		cin>>yolcu.yas;
     		veri.write(reinterpret_cast<char*>(&yolcu),sizeof(yolcu));
	    	cout<<"\n Baþka kayýt yapmak istiyor musunuz ? [E/H] ";
			kayit=getche();
			cout<<"\n";
			system("cls");
	    }	while(kayit=='e' || kayit=='E');
	        veri.close();
	    }
	    cout<<"------------------------------------------------------------"<<endl;
	    
	    ifstream veri("otobus.dat", ios::binary);
     	veri.seekg(0,ios::end);
    	int kisi=veri.tellg()/sizeof(yolcu);
    	cout<<"\n--> Sistemdeki Yolcu Sayýsý  : "<<kisi<<endl;
     	veri.close() ;
     	
		
		cout<<"\n-------------------------------------------------------------"<<endl;
        {
        ifstream veri;
	    veri.open("otobus.dat");
	    cout<<"\n Otobüste "<<kisi<<" yolcu bulunmaktadýr. "<<endl;
		if(kisi>0)
		{
			for(int j=0; j<kisi; j++)
		    {
		    	cout<<"\n-------------------------------------------------------------"<<endl;
		    	cout<<endl<<"Sistemdeki "<<j+1<<".Kayýtlý Yolcu"<<endl;
				veri.seekg(j*sizeof(yolcu));
				veri.read(reinterpret_cast<char*>(&yolcu),sizeof(yolcu));
				cout<<endl;
		      	cout<<"\n Yolcunun T.C Kimlik Numarasý  :  "<<yolcu.TC<<endl;
		    	cout<<"\n Yolcunun adý  :  "<<yolcu.ad<<endl;
		    	cout<<"\n Yolcunun soyadý  :  "<<yolcu.soyad<<endl;
		     	cout<<"\n Yolcunun Cinsiyeti  :  ";
		     	if(yolcu.cinsiyet=='e' || yolcu.cinsiyet=='E') 
			    {
					cout<<"Erkek";
				}
				if(yolcu.cinsiyet=='k' || yolcu.cinsiyet=='K') 
				{
					cout<<"Kýz";
				}
		    	cout<<"\n Yolcunun Yaþý  :  "<<yolcu.yas<<endl;
		    	cout<<"\n-------------------------------------------------------------"<<endl;
		    }
		}
		else
		{
			cout<<"\n Sistemde Aradýðýnýz Yolcu Bulunamadý. "<<endl;
			
		}
		veri.close();
    	}
		
		cout<<"\n-------------------------------------------------------------"<<endl;
		cout<<"\n Sisteme Girmiþ olduðunuz bilgiler ile ilgili herhangi bir deðiþiklik yapmak istiyor musunuz ? [E/H] :  ";
		cin>>degisiklik;
		if(degisiklik=='e'||degisiklik=='E')
		{
			goto devam;
		}
		else
		{
			goto son;
		}
		
		devam:
		bas:	
		cout<<"\n-------------------------------------------------------------"<<endl;
		cout<<"\n Yolcu aramak için [1]"<<endl;
		cout<<"\n Yolcunun kaydýný silmek için [2]"<<endl;
		cout<<"\n Yolcu bilgilerini deðiþtirmek için [3]"<<endl;
		cin>>sec;
		cout<<"-------------------------------------------------------------"<<endl;
		
		switch(sec)
		{
			case 1:
				{
					do
					{
						cout<<"\n-------------------------------------------------------------"<<endl;
						{
					    char ogi[100];
					    bool var;
					    ifstream otomasyon;
	                	veri.open("otobus.dat",ios::binary);
	                	
				    	cout<<"\n Sistemde Aramak Ýstediðiniz Yolcu : ";
				    	cin>>ogi;
				    	
				    	for(int i=0; i<kisi; i++)
				    	{
				     		veri.seekg(i*sizeof(yolcu));
	                  		veri.read(reinterpret_cast<char*>(&yolcu),sizeof(yolcu));
                			if(strcmp(yolcu.ad,ogi)==0)
                			{
                				cout<<" Aradýðýnýz Yolcu Bulundu. "<<endl;
                				var=true;
							
				    			veri.open("otobus.dat");
				    			cout<<"\n-------------------------------------------------------------"<<endl;
				    			cout<<"\n Yolcunun Adý  :  "<<yolcu.ad<<endl;
				    			cout<<"\n Yolcunun Soyadý  :  "<<yolcu.soyad<<endl;
				    			cout<<"\n Yolcunun T.C Kimlik Numarasý  :  "<<yolcu.TC<<endl;
                    			cout<<"\n Yolcunun Cinsiyeti [E/K]  :  ";
                    			if(yolcu.cinsiyet=='e' || yolcu.cinsiyet=='E') 
								{
			            	    	cout<<"Erkek";
	                   			}
			                   	if(yolcu.cinsiyet=='k' || yolcu.cinsiyet=='K') 
								{
			              	    	cout<<"Kýz";
	                 			}
                     			cout<<"\n Yolcunun Yaþý  :  "<<yolcu.yas<<endl;
                 			    cout<<"\n-------------------------------------------------------------"<<endl;
					    		
					    	}
						
				    	}
				    	if(!var)
				    	cout<<"\nXX Sistemde Aradýðýnýz Yolcu Bulunamadý."<<endl;
				    	veri.close();
				        }
				    	cout<<"--> Baþka Yolcu arayacak mýsýnýz ? [E/H]";
				    	f=getche();
					}while(secim=='e'||secim=='E');
					
					cout<<"\n--> Sisteme Girmiþ olduðunuz bilgileri deðiþtirmek istiyor musunuz ? [E/H] : ";
					cin>>l;
               		if(l=='e'||l=='E')
             		{
            			goto bas;
            		}
            		else
	             	{
	           	    	goto dev;
	             	}
				
					break;
				}
				
				case 2:
					{
						do
						{
							cout<<"\n-------------------------------------------------------------"<<endl;
							{							
				 			bool var=false;
				   		    char ogi[100];
				   		    
				   		    ifstream veri;
	                    	veri.open("otobus.txt",ios::binary);
	                    	
				         	cout<<" Sistemden silmek istediðiniz yolcuyu arayýnýz : ";
				         	cin>>ogi;
				    	
				        	for(int i=0; i<kisi; i++)
				         	{
				    	    	veri.seekg(i*sizeof(yolcu));
	                  	     	veri.read(reinterpret_cast<char*>(&yolcu),sizeof(yolcu));
                			    if(strcmp(yolcu.ad,ogi)==0)
                			    {
                			    	cout<<" Aradýðýnýz Yolcu Bulundu. "<<endl;
							        var=true;
				    		    	veri.open("otobus.dat");
				    		    	cout<<"\n-------------------------------------------------------------"<<endl;
				    		    	cout<<"\n Yolcunun Adý  :  "<<yolcu.ad<<endl;
				    		    	cout<<"\n Yolcunun Soyadý  :  "<<yolcu.soyad<<endl;
				    	    		cout<<"\n Yolcunun T.C Kimlik Numarasý  :  "<<yolcu.TC<<endl;
                           			cout<<"\n Yolcunun Cinsiyeti  :  ";
                           			if(yolcu.cinsiyet=='e' || yolcu.cinsiyet=='E') 
							      	{
			                	    	cout<<"Erkek";
	                   	     		}
			                     	if(yolcu.cinsiyet=='k' || yolcu.cinsiyet=='K') 
							    	{
			                 	    	cout<<"Kýz";
	                 	    		}
                         			cout<<"\n--> Yolcunun Yaþý  :  "<<yolcu.yas<<endl;              
                          			cout<<"\n-------------------------------------------------------------"<<endl;
				    			
			     					cout<<"\n Kaydýný Sileceðiniz Yolcu Bu mu ? [E/H] :  ";
		                     		secim=getche();
	                     			if(secim=='H' || secim=='h')
	                     			{
	                 			    	bilgiler yolcu;
                		    			ofstream veri;
                          				veri.open(" Saklý.dat ",ios::app | ios::binary);
              			    	     	strcpy(yolcu.ad,yolcu.ad);
              			    	     	
              	 		    	    	yolcu.TC=yolcu.TC;
               			    	     	yolcu.yas=yolcu.yas;
            			     	     	yolcu.cinsiyet=yolcu.cinsiyet;
					
	                	    	        veri.write(reinterpret_cast<char*>(&yolcu),sizeof(yolcu));
	             		    		    veri.close();
	             		     		}
			                      	 else if(secim=='E' || secim=='e')
			                     	{
			                    		var=true;
	                     			}
				
                     	        }
	                            else
                          		{
		                  	  	    bilgiler yolcu;
	                      			ofstream veri;
		               	     		veri.open(" Saklý.dat ",ios::app | ios::binary);
					
		                     		strcpy(yolcu.ad,yolcu.ad);
		                    		yolcu.TC=yolcu.TC;
			                   		yolcu.yas=yolcu.yas;
				                   	yolcu.cinsiyet=yolcu.cinsiyet;
				
				                   	veri.write(reinterpret_cast<char*>(&yolcu),sizeof(yolcu));
				                  	veri.close();
			                    }
							}
	                            veri.close();
						     	if(var)
	                         	{
	                         		remove("otobus.dat");
			                        rename("Saklý.dat","otobus.dat");
		                         	cout<<"\n--> Yolcunun Kaydý Silindi. "<<endl;
	                        	}
	                        	else 
	                        	{
		                    	    remove("Saklý.dat");
		                        	cout<<"\nXX Aradýðýnýz Yolcu Sistemde Bulunamadý."<<endl;
		                          	cout<<"\n-------------------------------------------------------------"<<endl;
	                        	}
	                        }
	                        	cout<<"\n--> Baþka Yolcu arayacak mýsýnýz ? [E/H]"<<endl;
			    	    	    f=getche();
		        				}while(secim=='e'||secim=='E');
		        				
				            	cout<<"\n--> Sisteme girmiþ olduðunuz bilgileri deðiþtirmek istiyor musunuz ? [E/H] : ";
				             	cin>>a;
               	            	if(a=='e'||a=='E')
             	            	{
            		            	goto bas;
                         		} 
                          		else
	                        	{
	                    	    	goto iki;
	                          	}
				    		break;
				 		
	               }
	               case 3:
	               	{
	               		do
						{
							cout<<"\n-------------------------------------------------------------"<<endl;
							{
				 			bool var=false;
				   		    char ogi[100];
				   		    	
				   		    ifstream veri;
	                    	veri.open("otobus.dat",ios::binary);	
	                    	
				         	cout<<"\n--> Sistemdeki Yolcunun Bilgilerini Güncellemek Ýçin Yolcunun Adýný Giriniz : ";
				         	cin>>ogi;
				    	
				        	for(int i=0; i<kisi; i++)
				         	{
				    	    	veri.seekg(i*sizeof(yolcu));
	                  	     	veri.read(reinterpret_cast<char*>(&yolcu),sizeof(yolcu));
                			    if(strcmp(yolcu.ad,ogi)==0)
                			    {
                			    	cout<<" Aradýðýnýz Yolcu Bulundu. "<<endl;
							        var=true;
				    		    	veri.open("otobus.dat");
				    		    	cout<<"\n Yolcunun Adý  :  "<<yolcu.ad<<endl;
				    		    	cout<<"\n Yolcunun Soyadý  :  "<<yolcu.soyad<<endl;
				    	    		cout<<"\n Yolcunun T.C Kimlik Numarasý  :  "<<yolcu.TC<<endl;
                           			cout<<"\n Yolcunun Cinsiyeti [E/K]  :  ";
                           			if(yolcu.cinsiyet=='e' || yolcu.cinsiyet=='E') 
							      	{
			                	    	cout<<"Erkek";
	                   	     		}
			                     	if(yolcu.cinsiyet=='k' || yolcu.cinsiyet=='K') 
							    	{
			                 	    	cout<<"Kýz";
	                 	    		}
                         			cout<<"\n Yolcunun yaþý  :  "<<yolcu.yas<<endl;
						            
						            cout<<"\n Düzeltmek istediðiniz kayýt bu mu ? [E/H] : ";
		                     		secim=getche();
	                     			if(secim=='H' || secim=='h')
	                     			{
	                 			    	bilgiler x_yolcu;
                		    			ofstream x_veri;
                          				x_veri.open(" Saklý.dat ",ios::app | ios::binary);
              			    	     	
										strcpy(x_yolcu.ad,yolcu.ad);
              	 		    	    	x_yolcu.TC=yolcu.TC;
               			    	     	x_yolcu.yas=yolcu.yas;
            			     	     	x_yolcu.cinsiyet=yolcu.cinsiyet;
					
	                	    	        x_veri.write(reinterpret_cast<char*>(&x_yolcu),sizeof(x_yolcu));
	             		    		    x_veri.close();
	             		    		
	             		    		}
			                      	else if(secim=='E' || secim=='e')
			                      	{
				                    	ofstream veri;
				                     	veri.open("Saklý.dat", ios::app | ios::binary);
				                     	cout<<"\n Yolcunun Adýný Giriniz  : ";
		                                cin>>yolcu.ad;
		                                cout<<"\n Yolcunun Soyadýný Giriniz  : ";
		                                cin>>yolcu.soyad;
		                                cout<<"\n Yolcunun T.C Kimlik Numarasýný Giriniz  : ";
		                                cin>>yolcu.TC;
		                                cout<<"\n Yolcunun Cinsiyetini Giriniz  [E/K] : ";
		                                cin>>yolcu.cinsiyet;
	                                    cout<<"\n Yolcunun Yaþýný Giriniz  : ";
		                                cin>>yolcu.yas;
	                    			 	veri.write(reinterpret_cast<char*>(&yolcu),sizeof(yolcu));
		                     			veri.close();
		                     		}
			                    	 else
			                     	 {
			                    	 	bilgiler x_yolcu;
			                    		ofstream x_veri;
			                    		x_veri.open(" Saklý.dat ",ios::app | ios::binary);
					
			                    		strcpy(x_yolcu.ad,yolcu.ad);
			                       		x_yolcu.TC=yolcu.TC;
				                     	x_yolcu.yas=yolcu.yas;
			                    		x_yolcu.cinsiyet=yolcu.cinsiyet;
	
			                     		x_veri.write(reinterpret_cast<char*>(&x_yolcu),sizeof(x_yolcu));
				                    	x_veri.close();
			                    	 }
								}
				    	    	veri.close();
                             	if(var)
                                {
	                            	remove("otobus.dat");
	                             	rename("Saklý.dat","otobus.dat");
	                              	cout<<"\n--> Yolcu Kaydý Düzeltildi."<<endl;
                               	}
                              	else
                             	{
                            		remove("otobus.dat");
                             		cout<<"\nXX Aradýðýnýz Yolcu Sistemde Bulunamadý."<<endl;
			                    }
			                }
			                }
			                cout<<"\n Baska Yolcu Kaydý Yapmak Ýstiyor musunuz ? [E/H] ";
	                        c=getche();
						    }while(secim=='e'||secim=='E');
						    cout<<"\n-------------------------------------------------------------"<<endl;
						    cout<<"\n Sisteme girmiþ olduðunuz bilgileri deðiþtirmek istiyor musunuz [E/H] : ";
				            cin>>b;
               	            if(b=='e'||b=='E')
             	            {
            		           	goto bas;
                         	} 
                          	else
	                        {
	                    	   	goto uc;
	                        }
						    break;
					    
					}
		}
		uc:
	    iki:
	    dev:	
	cout<<"\n-------------------------------------------------------------"<<endl;	
    cout<<"\n Yolcu Bilgileri Baþarýyla Kaydedilmiþtir. "<<endl;    
    cout<<"\n-------------------------------------------------------------"<<endl;		    
	}while(secim=='e'||secim=='E');
	son: 
	cout<<"\n  Otomasyon Sisteminden Çýkýþ Yaptýnýz. "<<endl;
	
	return 0;
}


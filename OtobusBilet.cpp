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
		cout<<" *____________ [-OTOBUS BILET REZERVASYON S�STEM�-] ____________* "<<endl;
		cout<<" *                      HO�GELD�N�Z                      * "<<endl;
	    cout<<" *********************************************************"<<endl; 
		cout<<" __________________________________________________________"<<endl;	    
	   	
		do
		{
			cout<<"-------------------------------------------------------------"<<endl;
			cout<<"\n Yolcunun T.C Kimlik Numaras�n� giriniz  : ";
	    	cin>>yolcu.TC;
			cout<<"\n Yolcunun ad�n� giriniz  : ";
		    cin>>yolcu.ad;
		    cout<<"\n Yolcunun soyad�n� giriniz  : ";
		    cin>>yolcu.soyad;
	    	cout<<"\n Yolcunun cinsiyetini giriniz  [E/K] : ";
       		cin>>yolcu.cinsiyet;
     		cout<<"\n Yolcunun Ya��n� Giriniz  : ";
     		cin>>yolcu.yas;
     		veri.write(reinterpret_cast<char*>(&yolcu),sizeof(yolcu));
	    	cout<<"\n Ba�ka kay�t yapmak istiyor musunuz ? [E/H] ";
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
    	cout<<"\n--> Sistemdeki Yolcu Say�s�  : "<<kisi<<endl;
     	veri.close() ;
     	
		
		cout<<"\n-------------------------------------------------------------"<<endl;
        {
        ifstream veri;
	    veri.open("otobus.dat");
	    cout<<"\n Otob�ste "<<kisi<<" yolcu bulunmaktad�r. "<<endl;
		if(kisi>0)
		{
			for(int j=0; j<kisi; j++)
		    {
		    	cout<<"\n-------------------------------------------------------------"<<endl;
		    	cout<<endl<<"Sistemdeki "<<j+1<<".Kay�tl� Yolcu"<<endl;
				veri.seekg(j*sizeof(yolcu));
				veri.read(reinterpret_cast<char*>(&yolcu),sizeof(yolcu));
				cout<<endl;
		      	cout<<"\n Yolcunun T.C Kimlik Numaras�  :  "<<yolcu.TC<<endl;
		    	cout<<"\n Yolcunun ad�  :  "<<yolcu.ad<<endl;
		    	cout<<"\n Yolcunun soyad�  :  "<<yolcu.soyad<<endl;
		     	cout<<"\n Yolcunun Cinsiyeti  :  ";
		     	if(yolcu.cinsiyet=='e' || yolcu.cinsiyet=='E') 
			    {
					cout<<"Erkek";
				}
				if(yolcu.cinsiyet=='k' || yolcu.cinsiyet=='K') 
				{
					cout<<"K�z";
				}
		    	cout<<"\n Yolcunun Ya��  :  "<<yolcu.yas<<endl;
		    	cout<<"\n-------------------------------------------------------------"<<endl;
		    }
		}
		else
		{
			cout<<"\n Sistemde Arad���n�z Yolcu Bulunamad�. "<<endl;
			
		}
		veri.close();
    	}
		
		cout<<"\n-------------------------------------------------------------"<<endl;
		cout<<"\n Sisteme Girmi� oldu�unuz bilgiler ile ilgili herhangi bir de�i�iklik yapmak istiyor musunuz ? [E/H] :  ";
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
		cout<<"\n Yolcu aramak i�in [1]"<<endl;
		cout<<"\n Yolcunun kayd�n� silmek i�in [2]"<<endl;
		cout<<"\n Yolcu bilgilerini de�i�tirmek i�in [3]"<<endl;
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
	                	
				    	cout<<"\n Sistemde Aramak �stedi�iniz Yolcu : ";
				    	cin>>ogi;
				    	
				    	for(int i=0; i<kisi; i++)
				    	{
				     		veri.seekg(i*sizeof(yolcu));
	                  		veri.read(reinterpret_cast<char*>(&yolcu),sizeof(yolcu));
                			if(strcmp(yolcu.ad,ogi)==0)
                			{
                				cout<<" Arad���n�z Yolcu Bulundu. "<<endl;
                				var=true;
							
				    			veri.open("otobus.dat");
				    			cout<<"\n-------------------------------------------------------------"<<endl;
				    			cout<<"\n Yolcunun Ad�  :  "<<yolcu.ad<<endl;
				    			cout<<"\n Yolcunun Soyad�  :  "<<yolcu.soyad<<endl;
				    			cout<<"\n Yolcunun T.C Kimlik Numaras�  :  "<<yolcu.TC<<endl;
                    			cout<<"\n Yolcunun Cinsiyeti [E/K]  :  ";
                    			if(yolcu.cinsiyet=='e' || yolcu.cinsiyet=='E') 
								{
			            	    	cout<<"Erkek";
	                   			}
			                   	if(yolcu.cinsiyet=='k' || yolcu.cinsiyet=='K') 
								{
			              	    	cout<<"K�z";
	                 			}
                     			cout<<"\n Yolcunun Ya��  :  "<<yolcu.yas<<endl;
                 			    cout<<"\n-------------------------------------------------------------"<<endl;
					    		
					    	}
						
				    	}
				    	if(!var)
				    	cout<<"\nXX Sistemde Arad���n�z Yolcu Bulunamad�."<<endl;
				    	veri.close();
				        }
				    	cout<<"--> Ba�ka Yolcu arayacak m�s�n�z ? [E/H]";
				    	f=getche();
					}while(secim=='e'||secim=='E');
					
					cout<<"\n--> Sisteme Girmi� oldu�unuz bilgileri de�i�tirmek istiyor musunuz ? [E/H] : ";
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
	                    	
				         	cout<<" Sistemden silmek istedi�iniz yolcuyu aray�n�z : ";
				         	cin>>ogi;
				    	
				        	for(int i=0; i<kisi; i++)
				         	{
				    	    	veri.seekg(i*sizeof(yolcu));
	                  	     	veri.read(reinterpret_cast<char*>(&yolcu),sizeof(yolcu));
                			    if(strcmp(yolcu.ad,ogi)==0)
                			    {
                			    	cout<<" Arad���n�z Yolcu Bulundu. "<<endl;
							        var=true;
				    		    	veri.open("otobus.dat");
				    		    	cout<<"\n-------------------------------------------------------------"<<endl;
				    		    	cout<<"\n Yolcunun Ad�  :  "<<yolcu.ad<<endl;
				    		    	cout<<"\n Yolcunun Soyad�  :  "<<yolcu.soyad<<endl;
				    	    		cout<<"\n Yolcunun T.C Kimlik Numaras�  :  "<<yolcu.TC<<endl;
                           			cout<<"\n Yolcunun Cinsiyeti  :  ";
                           			if(yolcu.cinsiyet=='e' || yolcu.cinsiyet=='E') 
							      	{
			                	    	cout<<"Erkek";
	                   	     		}
			                     	if(yolcu.cinsiyet=='k' || yolcu.cinsiyet=='K') 
							    	{
			                 	    	cout<<"K�z";
	                 	    		}
                         			cout<<"\n--> Yolcunun Ya��  :  "<<yolcu.yas<<endl;              
                          			cout<<"\n-------------------------------------------------------------"<<endl;
				    			
			     					cout<<"\n Kayd�n� Silece�iniz Yolcu Bu mu ? [E/H] :  ";
		                     		secim=getche();
	                     			if(secim=='H' || secim=='h')
	                     			{
	                 			    	bilgiler yolcu;
                		    			ofstream veri;
                          				veri.open(" Sakl�.dat ",ios::app | ios::binary);
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
		               	     		veri.open(" Sakl�.dat ",ios::app | ios::binary);
					
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
			                        rename("Sakl�.dat","otobus.dat");
		                         	cout<<"\n--> Yolcunun Kayd� Silindi. "<<endl;
	                        	}
	                        	else 
	                        	{
		                    	    remove("Sakl�.dat");
		                        	cout<<"\nXX Arad���n�z Yolcu Sistemde Bulunamad�."<<endl;
		                          	cout<<"\n-------------------------------------------------------------"<<endl;
	                        	}
	                        }
	                        	cout<<"\n--> Ba�ka Yolcu arayacak m�s�n�z ? [E/H]"<<endl;
			    	    	    f=getche();
		        				}while(secim=='e'||secim=='E');
		        				
				            	cout<<"\n--> Sisteme girmi� oldu�unuz bilgileri de�i�tirmek istiyor musunuz ? [E/H] : ";
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
	                    	
				         	cout<<"\n--> Sistemdeki Yolcunun Bilgilerini G�ncellemek ��in Yolcunun Ad�n� Giriniz : ";
				         	cin>>ogi;
				    	
				        	for(int i=0; i<kisi; i++)
				         	{
				    	    	veri.seekg(i*sizeof(yolcu));
	                  	     	veri.read(reinterpret_cast<char*>(&yolcu),sizeof(yolcu));
                			    if(strcmp(yolcu.ad,ogi)==0)
                			    {
                			    	cout<<" Arad���n�z Yolcu Bulundu. "<<endl;
							        var=true;
				    		    	veri.open("otobus.dat");
				    		    	cout<<"\n Yolcunun Ad�  :  "<<yolcu.ad<<endl;
				    		    	cout<<"\n Yolcunun Soyad�  :  "<<yolcu.soyad<<endl;
				    	    		cout<<"\n Yolcunun T.C Kimlik Numaras�  :  "<<yolcu.TC<<endl;
                           			cout<<"\n Yolcunun Cinsiyeti [E/K]  :  ";
                           			if(yolcu.cinsiyet=='e' || yolcu.cinsiyet=='E') 
							      	{
			                	    	cout<<"Erkek";
	                   	     		}
			                     	if(yolcu.cinsiyet=='k' || yolcu.cinsiyet=='K') 
							    	{
			                 	    	cout<<"K�z";
	                 	    		}
                         			cout<<"\n Yolcunun ya��  :  "<<yolcu.yas<<endl;
						            
						            cout<<"\n D�zeltmek istedi�iniz kay�t bu mu ? [E/H] : ";
		                     		secim=getche();
	                     			if(secim=='H' || secim=='h')
	                     			{
	                 			    	bilgiler x_yolcu;
                		    			ofstream x_veri;
                          				x_veri.open(" Sakl�.dat ",ios::app | ios::binary);
              			    	     	
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
				                     	veri.open("Sakl�.dat", ios::app | ios::binary);
				                     	cout<<"\n Yolcunun Ad�n� Giriniz  : ";
		                                cin>>yolcu.ad;
		                                cout<<"\n Yolcunun Soyad�n� Giriniz  : ";
		                                cin>>yolcu.soyad;
		                                cout<<"\n Yolcunun T.C Kimlik Numaras�n� Giriniz  : ";
		                                cin>>yolcu.TC;
		                                cout<<"\n Yolcunun Cinsiyetini Giriniz  [E/K] : ";
		                                cin>>yolcu.cinsiyet;
	                                    cout<<"\n Yolcunun Ya��n� Giriniz  : ";
		                                cin>>yolcu.yas;
	                    			 	veri.write(reinterpret_cast<char*>(&yolcu),sizeof(yolcu));
		                     			veri.close();
		                     		}
			                    	 else
			                     	 {
			                    	 	bilgiler x_yolcu;
			                    		ofstream x_veri;
			                    		x_veri.open(" Sakl�.dat ",ios::app | ios::binary);
					
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
	                             	rename("Sakl�.dat","otobus.dat");
	                              	cout<<"\n--> Yolcu Kayd� D�zeltildi."<<endl;
                               	}
                              	else
                             	{
                            		remove("otobus.dat");
                             		cout<<"\nXX Arad���n�z Yolcu Sistemde Bulunamad�."<<endl;
			                    }
			                }
			                }
			                cout<<"\n Baska Yolcu Kayd� Yapmak �stiyor musunuz ? [E/H] ";
	                        c=getche();
						    }while(secim=='e'||secim=='E');
						    cout<<"\n-------------------------------------------------------------"<<endl;
						    cout<<"\n Sisteme girmi� oldu�unuz bilgileri de�i�tirmek istiyor musunuz [E/H] : ";
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
    cout<<"\n Yolcu Bilgileri Ba�ar�yla Kaydedilmi�tir. "<<endl;    
    cout<<"\n-------------------------------------------------------------"<<endl;		    
	}while(secim=='e'||secim=='E');
	son: 
	cout<<"\n  Otomasyon Sisteminden ��k�� Yapt�n�z. "<<endl;
	
	return 0;
}


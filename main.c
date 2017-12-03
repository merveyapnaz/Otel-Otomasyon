#include <stdio.h>
#include <stdlib.h>

int main()
{
    char mevsim, devam, odatipi, odemetipi;
    int hafta=0,misafirdegeri=0, odasecimi=0, yanlisgirdi=0, odalar[100][36], i, j, yuzdesayaci=0, ucret=0, odasecimi2=1, misafirsayisi=0,odasayaci=0, misafirsayaci=0;
    for(i=0; i<100; i++)
    {
        for(j=0; j<36; j++)
        {
            odalar[i][j] = 0;
        }
    }


    do
    {
        printf("\nHangi mevsimde konaklama yapmak istersiniz?\nSonbahar icin 'S'   Bahar icin 'B'   Yaz icin 'Y' tusuna basiniz.\t");
        scanf(" %c",&mevsim);
        switch(mevsim)
        {
            case 'S':
            case 's':
                for(i=0; i<3; i++)
                {
                    printf("\nSonbaharin kacinci haftasinda konaklama yapilacagini giriniz\t");
                    scanf("%d",&hafta);
                    if(hafta<1 || hafta >12)
                    {
                        yanlisgirdi++;
                    }
                    else
                    {
                        break;
                    }
                }
                if(yanlisgirdi>=3)
                {
                    exit(0);
                }

                printf("\nLutfen oda tipini seciniz.\nStandart odalar icin 'S'   Large Deluxe odalar icin 'L'   Deluxe odalar icin 'D' tusuna basiniz");
                scanf(" %c",&odatipi);
                switch(odatipi)
                {
                    case 'S':
                    case 's':
                        do
                        {
                            for(i=1; i<=100; i++)
                            {
                                if(odalar[i-1][23+hafta-1]==0 && i%2==1)
                                {
                                    printf("%d--",i);
                                }

                            }

                            printf("\nNolu odalar standart odalara dahildir, birini seciniz.");
                            scanf("%d",&odasecimi);

                            if(odasecimi%2!=1)
                            {
                                printf("\nSectiginiz oda standart odalara dahil degildir. Lutfen yeni oda seciniz.\n");
                                odasecimi2=0;

                            }
                            else if(odalar[odasecimi-1][23+hafta-1] == 1 )
                            {
                                printf("\nSectiginiz oda doludur lutfen baska oda seciniz.\n");
                                odasecimi2=0;
                            }
                            else
                            {
                                odasecimi2=1;
                            }
                        }
                        while(odasecimi2==0);
                        odalar[odasecimi-1][23+hafta-1]=1;
                        do
                        {
                            printf("\nKalacak misafir sayisini giriniz.\t");
                            scanf("%d",&misafirsayisi);
                            if(misafirsayisi<=0)
                            {
                                printf("\nMisafir sayisi 0'dan kucuk olamaz. Lutfen tekrar deneyiniz.");
                                misafirdegeri=0;

                            }
                            else
                                misafirdegeri=1;
                        }
                        while(misafirdegeri==0);
                        misafirsayaci=misafirsayisi;
                        while(misafirsayaci>4)
                        {
                            printf("\nMisafir sayiniz oda kapasitesinden fazladir. Lutfen geriye kalan misafirleriniz icin yeni oda secin.\n");
                            do
                            {
                                for(i=1; i<=100; i++)
                                {
                                    if(odalar[i-1][23+hafta-1]==0 && i%2==1)
                                    {
                                        printf("%d--",i);
                                    }

                                }

                            printf("\nNolu odalar standart odalara dahildir, birini seciniz.");
                            scanf("%d",&odasecimi);

                            if(odasecimi%2!=1)
                            {
                                printf("\nSectiginiz oda standart odalara dahil degildir. Lutfen yeni oda seciniz.\n");
                                odasecimi2=0;

                            }
                            else if(odalar[odasecimi-1][23+hafta-1] == 1 )
                            {
                                printf("\nSectiginiz oda doludur lutfen baska oda seciniz.\n");
                                odasecimi2=0;
                            }
                            else
                            {
                                odasecimi2=1;
                            }
                        }
                        while(odasecimi2==0);
                        odalar[odasecimi-1][23+hafta-1]=1;
                        misafirsayaci-=4;
                        }
                        printf("\nLutfen odeme tipini seciniz.\nOn odemeli rezervasyon icin 'O'   Havale ile odeme icin 'H'   Standart odeme icin 'S' Tusuna basiniz.\t");
                        scanf(" %c",&odemetipi);
                        switch(odemetipi)
                        {
                            case 'O':
                            case 'o':
                                ucret=((misafirsayisi*25*7)-((misafirsayisi*25*7)*15/100));
                                printf("\nRezervasyon ucretiniz %d$ dir.",ucret);
                                printf("\nOtelimizdeki dolu odalarin yuzdesi:\n");
                                for(i=23; i<36; i++)
                                {
                                    for(j=0; j<100; j++)
                                    {
                                        if(odalar[j][i]==1)
                                        {
                                            yuzdesayaci++;
                                        }
                                    }
                                printf("%d. hafta icin  = %%%d dir.\n",i-22,yuzdesayaci);
                                yuzdesayaci=0;
                                }
                                printf("Baska rezervasyon yapmak ister misiniz\(E\\H)");
                                scanf(" %c", &devam);

                                break;
                                break;

                            case 'H':
                            case 'h':
                                if(misafirsayisi>5)
                                {
                                    ucret=(misafirsayisi*25*7)-(25*7*75/100);
                                }
                                else if(misafirsayisi>3)
                                {
                                    ucret=(misafirsayisi*25*7)-(25*7*50/100);
                                }
                                else
                                {
                                    ucret=misafirsayisi*25*7;
                                }
                                printf("\nRezervasyon ucretiniz %d$ dir.",ucret);
                                printf("\nOtelimizdeki dolu odalarin yuzdesi:\n");
                                for(i=23; i<36; i++)
                                {
                                    for(j=0; j<100; j++)
                                    {
                                        if(odalar[j][i]==1)
                                        {
                                            yuzdesayaci++;
                                        }
                                    }
                                printf("%d. hafta icin  = %%%d dir.\n",i-22,yuzdesayaci);
                                yuzdesayaci=0;
                                }
                                printf("\nBaska rezervasyon yapmak ister misiniz\(E\\H)");
                                scanf(" %c", &devam);
                                break;
                                break;

                            case 'S':
                            case 's':
                                ucret=misafirsayisi*25*7;
                                printf("\nRezervasyon ucretiniz %d$ dir.",ucret);
                                printf("\nOtelimizdeki dolu odalarin yuzdesi:\n");
                                for(i=23; i<36; i++)
                                {
                                    for(j=0; j<100; j++)
                                    {
                                        if(odalar[j][i]==1)
                                        {
                                            yuzdesayaci++;
                                        }
                                    }
                                printf("%d. hafta icin  = %%%d dir.\n",i-22,yuzdesayaci);
                                yuzdesayaci=0;
                                }
                                printf("\nBaska rezervasyon yapmak ister misiniz\(E\\H)");
                                scanf(" %c", &devam);
                                break;
                                break;

                            default:
                                printf("\nYanlis tusa bastiniz.");
                                break;


                        }

                        break;
                        break;

                    case 'L':
                    case 'l':

                        do
                        {
                            for(i=1; i<=100; i++)
                            {
                                if(odalar[i-1][23+hafta-1]==0 && i%2==0 && i%6==0)
                                {
                                    printf("%d--",i);
                                }

                            }

                            printf("\nNolu odalar large deluxe odalara dahildir, birini seciniz.");
                            scanf("%d",&odasecimi);

                            if(odasecimi%2!=0 || odasecimi%6!=0 || odasecimi==0)
                            {
                                printf("\nSectiginiz oda large deluxe odalara dahil degildir. Lutfen yeni oda seciniz.\n");
                                odasecimi2=0;

                            }
                            else if(odalar[odasecimi-1][23+hafta-1]==1)
                            {
                                printf("\nSectiginiz oda doludur lutfen baska oda seciniz.\n");
                                odasecimi2=0;
                            }
                            else
                            {
                                odasecimi2=1;
                            }
                        }
                        while(odasecimi2==0);
                        odalar[odasecimi-1][23+hafta-1]=1;
                        odasayaci++;

                        do
                        {
                            printf("\nKalacak misafir sayisini giriniz.\t");
                            scanf("%d",&misafirsayisi);
                            if(misafirsayisi<=0)
                            {
                                printf("\nMisafir sayisi 0'dan kucuk olamaz. Lutfen tekrar deneyiniz.");
                                misafirdegeri=0;

                            }
                            else
                                misafirdegeri=1;
                        }
                        while(misafirdegeri==0);
                        misafirsayaci=misafirsayisi;

                        while(misafirsayaci>7)
                        {
                            printf("\nMisafir sayiniz oda kapasitesinden fazladir. Lutfen geriye kalan misafirleriniz icin yeni oda secin.\n");
                            do
                        {
                            for(i=1; i<=100; i++)
                            {
                                if(odalar[i-1][23+hafta-1]==0 && i%2==0 && i%6==0)
                                {
                                    printf("%d--",i);
                                }

                            }

                            printf("\nNolu odalar large deluxe odalara dahildir, birini seciniz.");
                            scanf("%d",&odasecimi);

                            if(odasecimi%2!=0 || odasecimi%6!=0 || odasecimi==0)
                            {
                                printf("\nSectiginiz oda large deluxe odalara dahil degildir. Lutfen yeni oda seciniz.\n");
                                odasecimi2=0;

                            }
                            else if(odalar[odasecimi-1][23+hafta-1]==1)
                            {
                                printf("\nSectiginiz oda doludur lutfen baska oda seciniz.\n");
                                odasecimi2=0;
                            }
                            else
                            {
                                odasecimi2=1;
                            }
                        }
                        while(odasecimi2==0);
                        odalar[odasecimi-1][23+hafta-1]=1;
                        odasayaci++;
                        misafirsayaci-=7;
                        }
                        printf("\nLutfen odeme tipini seciniz.\nOn odemeli rezervasyon icin 'O'   Havale ile odeme icin 'H'   Standart odeme icin 'S' Tusuna basiniz.\t");
                        scanf(" %c",&odemetipi);
                        switch(odemetipi)
                        {
                            case 'O':
                            case 'o':
                                ucret=odasayaci*((250*7)-(250*7*15/100));
                                printf("\nRezervasyon ucretiniz %d$ dir.",ucret);
                                printf("\nOtelimizdeki dolu odalarin yuzdesi:\n");
                                for(i=23; i<36; i++)
                                {
                                    for(j=0; j<100; j++)
                                    {
                                        if(odalar[j][i]==1)
                                        {
                                            yuzdesayaci++;
                                        }
                                    }
                                printf("%d. hafta icin  = %%%d dir.\n",i-23,yuzdesayaci);
                                yuzdesayaci=0;
                                }
                                printf("Baska rezervasyon yapmak ister misiniz\(E\\H)");
                                scanf(" %c", &devam);

                                break;
                                break;

                            case 'H':
                            case 'h':
                                ucret=250*7*odasayaci;
                                printf("\nRezervasyon ucretiniz %d$ dir.",ucret);
                                printf("\nOtelimizdeki dolu odalarin yuzdesi:\n");
                                for(i=23; i<36; i++)
                                {
                                    for(j=0; j<100; j++)
                                    {
                                        if(odalar[j][i]==1)
                                        {
                                            yuzdesayaci++;
                                        }
                                    }
                                printf("%d. hafta icin  = %%%d dir.\n",i-22,yuzdesayaci);
                                yuzdesayaci=0;
                                }
                                printf("Baska rezervasyon yapmak ister misiniz\(E\\H)");
                                scanf(" %c", &devam);
                                break;
                                break;

                            case 'S':
                            case 's':
                                ucret=250*7*odasayaci;
                                printf("\nRezervasyon ucretiniz %d$ dir.",ucret);
                                printf("\nOtelimizdeki dolu odalarin yuzdesi:\n");
                                for(i=23; i<36; i++)
                                {
                                    for(j=0; j<100; j++)
                                    {
                                        if(odalar[j][i]==1)
                                        {
                                            yuzdesayaci++;
                                        }
                                    }
                                printf("%d. hafta icin  = %%%d dir.\n",i-22,yuzdesayaci);
                                yuzdesayaci=0;
                                }
                                printf("\nBaska rezervasyon yapmak ister misiniz\(E\\H)");
                                scanf(" %c", &devam);
                                break;
                                break;

                            default:
                                printf("\nYanlis tusa bastiniz.");
                                break;


                        }
                        break;
                        break;

                    case 'D':
                    case 'd':
                        do
                        {
                            for(i=1; i<=100; i++)
                            {
                                if(odalar[i-1][23+hafta-1]==0 && i%2==0)
                                {
                                    if(i%6==0)
                                    {
                                        continue;
                                    }
                                    printf("%d--",i);
                                }

                            }

                            printf("\nNolu odalar deluxe odalara dahildir, birini seciniz.");
                            scanf("%d",&odasecimi);

                            if(odasecimi%2!=0 || odasecimi%6==0 || odasecimi==0)
                            {
                                printf("\nSectiginiz oda deluxe odalara dahil degildir. Lutfen yeni oda seciniz.\n");
                                odasecimi2=0;

                            }
                            else if(odalar[odasecimi-1][23+hafta-1]==1)
                            {
                                printf("\nSectiginiz oda doludur lutfen baska oda seciniz.\n");
                                odasecimi2=0;
                            }
                            else
                            {
                                odasecimi2=1;
                            }
                        }
                        while(odasecimi2==0);
                        odalar[odasecimi-1][23+hafta-1]=1;
                        do
                        {
                            printf("\nKalacak misafir sayisini giriniz.\t");
                            scanf("%d",&misafirsayisi);
                            if(misafirsayisi<=0)
                            {
                                printf("\nMisafir sayisi 0'dan kucuk olamaz. Lutfen tekrar deneyiniz.");
                                misafirdegeri=0;

                            }
                            else
                                misafirdegeri=1;
                        }
                        while(misafirdegeri==0);
                        misafirsayaci=misafirsayisi;
                        while(misafirsayaci>4)
                        {
                            printf("\nMisafir sayiniz oda kapasitesinden fazladir. Lutfen geriye kalan misafirleriniz icin yeni oda secin.\n");
                            do
                        {
                            for(i=1; i<=100; i++)
                            {
                                if(odalar[i-1][23+hafta-1]==0 && i%2==0)
                                {
                                    if(i%6==0)
                                    {
                                        continue;
                                    }
                                    printf("%d--",i);
                                }

                            }

                            printf("\nNolu odalar deluxe odalara dahildir, birini seciniz.");
                            scanf("%d",&odasecimi);

                            if(odasecimi%2!=0 || odasecimi%6==0 || odasecimi==0)
                            {
                                printf("\nSectiginiz oda deluxe odalara dahil degildir. Lutfen yeni oda seciniz.\n");
                                odasecimi2=0;

                            }
                            else if(odalar[odasecimi-1][23+hafta-1]==1)
                            {
                                printf("\nSectiginiz oda doludur lutfen baska oda seciniz.\n");
                                odasecimi2=0;
                            }
                            else
                            {
                                odasecimi2=1;
                            }
                        }
                        while(odasecimi2==0);
                        odalar[odasecimi-1][23+hafta-1]=1;
                        misafirsayaci-=4;
                        }
                        printf("\nLutfen odeme tipini seciniz.\nOn odemeli rezervasyon icin 'O'   Havale ile odeme icin 'H'   Standart odeme icin 'S' Tusuna basiniz.\t");
                        scanf(" %c",&odemetipi);
                        switch(odemetipi)
                        {
                            case 'O':
                            case 'o':
                                ucret=((misafirsayisi*50*7)-((misafirsayisi*50*7)*15/100));
                                printf("\nRezervasyon ucretiniz %d$ dir.",ucret);
                                printf("\nOtelimizdeki dolu odalarin yuzdesi:\n");
                                for(i=23; i<36; i++)
                                {
                                    for(j=0; j<100; j++)
                                    {
                                        if(odalar[j][i]==1)
                                        {
                                            yuzdesayaci++;
                                        }
                                    }
                                printf("%d. hafta icin  = %%%d dir.\n",i-22,yuzdesayaci);
                                yuzdesayaci=0;
                                }
                                printf("Baska rezervasyon yapmak ister misiniz\(E\\H)");
                                scanf(" %c", &devam);
                                break;
                                break;

                            case 'H':
                            case 'h':
                                if(misafirsayisi>5)
                                {
                                    ucret=(misafirsayisi*50*7)-(50*7*75/100);
                                }
                                else if(misafirsayisi>3)
                                {
                                    ucret=(misafirsayisi*50*7)-(50*7*50/100);
                                }
                                else
                                {
                                    ucret=misafirsayisi*50*7;
                                }
                                printf("\nRezervasyon ucretiniz %d$ dir.",ucret);
                                printf("\nOtelimizdeki dolu odalarin yuzdesi:\n");
                                for(i=23; i<36; i++)
                                {
                                    for(j=0; j<100; j++)
                                    {
                                        if(odalar[j][i]==1)
                                        {
                                            yuzdesayaci++;
                                        }
                                    }
                                printf("%d. hafta icin  = %%%d dir.\n",i-22,yuzdesayaci);
                                yuzdesayaci=0;
                                }
                                printf("Baska rezervasyon yapmak ister misiniz\(E\\H)");
                                scanf(" %c", &devam);
                                break;
                                break;

                            case 'S':
                            case 's':
                                ucret=misafirsayisi*50*7;
                                printf("\nRezervasyon ucretiniz %d$ dir.",ucret);
                                printf("\nOtelimizdeki dolu odalarin yuzdesi:\n");
                                for(i=23; i<36; i++)
                                {
                                    for(j=0; j<100; j++)
                                    {
                                        if(odalar[j][i]==1)
                                        {
                                            yuzdesayaci++;
                                        }
                                    }
                                printf("%d. hafta icin  = %%%d dir.\n",i-22,yuzdesayaci);
                                yuzdesayaci=0;
                                }
                                printf("Baska rezervasyon yapmak ister misiniz\(E\\H)");
                                scanf(" %c", &devam);
                                break;
                                break;
                        }

                        break;
                        break;

                    default:
                        printf("\nYanlis tusa bastiniz.");
                        break;

                }


                break;
                break;

            case 'B':
            case 'b':

                for(i=0; i<3; i++)
                {
                    printf("\nBaharin kacinci haftasinda konaklama yapilacagini giriniz\t");
                    scanf("%d",&hafta);
                    if(hafta<1 || hafta >12)
                    {
                        yanlisgirdi++;
                    }
                    else
                    {
                        break;
                    }
                }
                if(yanlisgirdi>=3)
                {
                    exit(0);
                }

                printf("\nLutfen oda tipini seciniz.\nStandart odalar icin 'S'   Large Deluxe odalar icin 'L'   Deluxe odalar icin 'D' tusuna basiniz");
                scanf(" %c",&odatipi);
                switch(odatipi)
                {
                    case 'S':
                    case 's':
                        do
                        {
                            for(i=1; i<=100; i++)
                            {
                                if(odalar[i-1][hafta-1]==0 && i%2==1)
                                {
                                    printf("%d--",i);
                                }

                            }

                            printf("\nNolu odalar standart odalara dahildir, birini seciniz.");
                            scanf("%d",&odasecimi);

                            if(odasecimi%2!=1)
                            {
                                printf("\nSectiginiz oda standart odalara dahil degildir. Lutfen yeni oda seciniz.\n");
                                odasecimi2=0;

                            }
                            else if(odalar[odasecimi-1][hafta-1] == 1 )
                            {
                                printf("\nSectiginiz oda doludur lutfen baska oda seciniz.\n");
                                odasecimi2=0;
                            }
                            else
                            {
                                odasecimi2=1;
                            }
                        }
                        while(odasecimi2==0);
                        odalar[odasecimi-1][hafta-1]=1;

                        do
                        {
                            printf("\nKalacak misafir sayisini giriniz.\t");
                            scanf("%d",&misafirsayisi);
                            if(misafirsayisi<=0)
                            {
                                printf("\nMisafir sayisi 0'dan kucuk olamaz. Lutfen tekrar deneyiniz.");
                                misafirdegeri=0;

                            }
                            else
                                misafirdegeri=1;
                        }
                        while(misafirdegeri==0);
                        misafirsayaci=misafirsayisi;
                        while(misafirsayaci>4)
                        {
                            printf("\nMisafir sayiniz oda kapasitesinden fazladir. Lutfen geriye kalan misafirleriniz icin yeni oda secin.\n");
                            do
                        {
                            for(i=1; i<=100; i++)
                            {
                                if(odalar[i-1][hafta-1]==0 && i%2==1)
                                {
                                    printf("%d--",i);
                                }

                            }

                            printf("\nNolu odalar standart odalara dahildir, birini seciniz.");
                            scanf("%d",&odasecimi);

                            if(odasecimi%2!=1)
                            {
                                printf("\nSectiginiz oda standart odalara dahil degildir. Lutfen yeni oda seciniz.\n");
                                odasecimi2=0;

                            }
                            else if(odalar[odasecimi-1][hafta-1] == 1 )
                            {
                                printf("\nSectiginiz oda doludur lutfen baska oda seciniz.\n");
                                odasecimi2=0;
                            }
                            else
                            {
                                odasecimi2=1;
                            }
                        }
                        while(odasecimi2==0);
                        odalar[odasecimi-1][hafta-1]=1;
                        misafirsayaci-=4;
                        }
                        printf("\nLutfen odeme tipini seciniz.\nOn odemeli rezervasyon icin 'O'   Havale ile odeme icin 'H'   Standart odeme icin 'S' Tusuna basiniz.\t");
                        scanf(" %c",&odemetipi);
                        switch(odemetipi)
                        {
                            case 'O':
                            case 'o':
                                ucret=((misafirsayisi*40*7)-((misafirsayisi*40*7)*15/100));
                                printf("\nRezervasyon ucretiniz %d$ dir.",ucret);
                                printf("\nOtelimizdeki dolu odalarin yuzdesi:\n");
                                for(i=0; i<12; i++)
                                {
                                    for(j=0; j<100; j++)
                                    {
                                        if(odalar[j][i]==1)
                                        {
                                            yuzdesayaci++;
                                        }
                                    }
                                printf("%d. hafta icin  = %%%d dir.\n",i+1,yuzdesayaci);
                                yuzdesayaci=0;
                                }
                                printf("Baska rezervasyon yapmak ister misiniz\(E\\H)");
                                scanf(" %c", &devam);

                                break;
                                break;

                            case 'H':
                            case 'h':
                                if(misafirsayisi>5)
                                {
                                    ucret=(misafirsayisi*40*7)-(40*7*75/100);
                                }
                                else if(misafirsayisi>3)
                                {
                                    ucret=(misafirsayisi*40*7)-(40*7*50/100);
                                }
                                else
                                {
                                    ucret=misafirsayisi*40*7;
                                }
                                printf("\nRezervasyon ucretiniz %d$ dir.",ucret);
                                printf("\nOtelimizdeki dolu odalarin yuzdesi:\n");
                                for(i=0; i<12; i++)
                                {
                                    for(j=0; j<100; j++)
                                    {
                                        if(odalar[j][i]==1)
                                        {
                                            yuzdesayaci++;
                                        }
                                    }
                                printf("%d. hafta icin  = %%%d dir.\n",i+1,yuzdesayaci);
                                yuzdesayaci=0;
                                }
                                printf("Baska rezervasyon yapmak ister misiniz\(E\\H)");
                                scanf(" %c", &devam);
                                break;
                                break;

                            case 'S':
                            case 's':
                                ucret=misafirsayisi*40*7;
                                printf("\nRezervasyon ucretiniz %d$ dir.",ucret);
                                printf("\nOtelimizdeki dolu odalarin yuzdesi:\n");
                                for(i=0; i<12; i++)
                                {
                                    for(j=0; j<100; j++)
                                    {
                                        if(odalar[j][i]==1)
                                        {
                                            yuzdesayaci++;
                                        }
                                    }
                                printf("%d. hafta icin  = %%%d dir.\n",i+1,yuzdesayaci);
                                yuzdesayaci=0;
                                }
                                printf("Baska rezervasyon yapmak ister misiniz\(E\\H)");
                                scanf(" %c", &devam);
                                break;
                                break;

                            default:
                                printf("\nYanlis tusa bastiniz.");
                                break;


                        }

                        break;
                        break;

                    case 'L':
                    case 'l':

                        do
                        {
                            for(i=1; i<=100; i++)
                            {
                                if(odalar[i-1][hafta-1]==0 && i%2==0 && i%6==0)
                                {
                                    printf("%d--",i);
                                }

                            }

                            printf("\nNolu odalar large deluxe odalara dahildir, birini seciniz.");
                            scanf("%d",&odasecimi);

                            if(odasecimi%2!=0 || odasecimi%6!=0 || odasecimi==0)
                            {
                                printf("\nSectiginiz oda large deluxe odalara dahil degildir. Lutfen yeni oda seciniz.\n");
                                odasecimi2=0;

                            }
                            else if(odalar[odasecimi-1][hafta-1]==1)
                            {
                                printf("\nSectiginiz oda doludur lutfen baska oda seciniz.\n");
                                odasecimi2=0;
                            }
                            else
                            {
                                odasecimi2=1;
                            }
                        }
                        while(odasecimi2==0);
                        odalar[odasecimi-1][hafta-1]=1;
                        odasayaci++;

                        do
                        {
                            printf("\nKalacak misafir sayisini giriniz.\t");
                            scanf("%d",&misafirsayisi);
                            if(misafirsayisi<=0)
                            {
                                printf("\nMisafir sayisi 0'dan kucuk olamaz. Lutfen tekrar deneyiniz.");
                                misafirdegeri=0;

                            }
                            else
                                misafirdegeri=1;
                        }
                        while(misafirdegeri==0);
                        misafirsayaci=misafirsayisi;

                        while(misafirsayaci>7)
                        {
                            printf("\nMisafir sayiniz oda kapasitesinden fazladir. Lutfen geriye kalan misafirleriniz icin yeni oda secin.\n");
                           do
                        {
                            for(i=1; i<=100; i++)
                            {
                                if(odalar[i-1][hafta-1]==0 && i%2==0 && i%6==0)
                                {
                                    printf("%d--",i);
                                }

                            }

                            printf("\nNolu odalar large deluxe odalara dahildir, birini seciniz.");
                            scanf("%d",&odasecimi);

                            if(odasecimi%2!=0 || odasecimi%6!=0 || odasecimi==0)
                            {
                                printf("\nSectiginiz oda large deluxe odalara dahil degildir. Lutfen yeni oda seciniz.\n");
                                odasecimi2=0;

                            }
                            else if(odalar[odasecimi-1][hafta-1]==1)
                            {
                                printf("\nSectiginiz oda doludur lutfen baska oda seciniz.\n");
                                odasecimi2=0;
                            }
                            else
                            {
                                odasecimi2=1;
                            }
                        }
                        while(odasecimi2==0);
                        odalar[odasecimi-1][hafta-1]=1;
                        odasayaci++;
                        misafirsayaci-=7;
                        }
                        printf("\nLutfen odeme tipini seciniz.\nOn odemeli rezervasyon icin 'O'   Havale ile odeme icin 'H'   Standart odeme icin 'S' Tusuna basiniz.\t");
                        scanf(" %c",&odemetipi);
                        switch(odemetipi)
                        {
                            case 'O':
                            case 'o':
                                ucret=odasayaci*((300*7)-(300*7*15/100));
                                printf("\nRezervasyon ucretiniz %d$ dir.",ucret);
                                printf("\nOtelimizdeki dolu odalarin yuzdesi:\n");
                                for(i=0; i<12; i++)
                                {
                                    for(j=0; j<100; j++)
                                    {
                                        if(odalar[j][i]==1)
                                        {
                                            yuzdesayaci++;
                                        }
                                    }
                                printf("%d. hafta icin  = %%%d dir.\n",i-23,yuzdesayaci);
                                yuzdesayaci=0;
                                }
                                printf("Baska rezervasyon yapmak ister misiniz\(E\\H)");
                                scanf(" %c", &devam);

                                break;
                                break;

                            case 'H':
                            case 'h':
                                ucret=300*7*odasayaci;
                                printf("\nRezervasyon ucretiniz %d$ dir.",ucret);
                                printf("\nOtelimizdeki dolu odalarin yuzdesi:\n");
                                for(i=0; i<12; i++)
                                {
                                    for(j=0; j<100; j++)
                                    {
                                        if(odalar[j][i]==1)
                                        {
                                            yuzdesayaci++;
                                        }
                                    }
                                printf("%d. hafta icin  = %%%d dir.\n",i+1,yuzdesayaci);
                                yuzdesayaci=0;
                                }
                                printf("\nBaska rezervasyon yapmak ister misiniz\(E\\H)");
                                scanf(" %c", &devam);
                                break;
                                break;

                            case 'S':
                            case 's':
                                ucret=300*7*odasayaci;
                                printf("\nRezervasyon ucretiniz %d$ dir.",ucret);
                                printf("\nOtelimizdeki dolu odalarin yuzdesi:\n");
                                for(i=0; i<12; i++)
                                {
                                    for(j=0; j<100; j++)
                                    {
                                        if(odalar[j][i]==1)
                                        {
                                            yuzdesayaci++;
                                        }
                                    }
                                printf("%d. hafta icin  = %%%d dir.\n",i+1,yuzdesayaci);
                                yuzdesayaci=0;
                                }
                                printf("\nBaska rezervasyon yapmak ister misiniz\(E\\H)");
                                scanf(" %c", &devam);
                                break;
                                break;

                            default:
                                printf("\nYanlis tusa bastiniz.");
                                break;


                        }
                        break;
                        break;

                    case 'D':
                    case 'd':
                        do
                        {
                            for(i=1; i<=100; i++)
                            {
                                if(odalar[i-1][hafta-1]==0 && i%2==0)
                                {
                                    if(i%6==0)
                                    {
                                        continue;
                                    }
                                    printf("%d--",i);
                                }

                            }

                            printf("\nNolu odalar deluxe odalara dahildir, birini seciniz.");
                            scanf("%d",&odasecimi);

                            if(odasecimi%2!=0 || odasecimi%6==0 || odasecimi==0)
                            {
                                printf("\nSectiginiz oda deluxe odalara dahil degildir. Lutfen yeni oda seciniz.\n");
                                odasecimi2=0;

                            }
                            else if(odalar[odasecimi-1][hafta-1]==1)
                            {
                                printf("\nSectiginiz oda doludur lutfen baska oda seciniz.\n");
                                odasecimi2=0;
                            }
                            else
                            {
                                odasecimi2=1;
                            }
                        }
                        while(odasecimi2==0);
                        odalar[odasecimi-1][hafta-1]=1;
                        do
                        {
                            printf("\nKalacak misafir sayisini giriniz.\t");
                            scanf("%d",&misafirsayisi);
                            if(misafirsayisi<=0)
                            {
                                printf("\nMisafir sayisi 0'dan kucuk olamaz. Lutfen tekrar deneyiniz.");
                                misafirdegeri=0;

                            }
                            else
                                misafirdegeri=1;
                        }
                        while(misafirdegeri==0);
                        misafirsayaci=misafirsayisi;
                        while(misafirsayaci>4)
                        {
                            printf("\nMisafir sayiniz oda kapasitesinden fazladir. Lutfen geriye kalan misafirleriniz icin yeni oda secin.\n");
                            do
                        {
                            for(i=1; i<=100; i++)
                            {
                                if(odalar[i-1][hafta-1]==0 && i%2==0)
                                {
                                    if(i%6==0)
                                    {
                                        continue;
                                    }
                                    printf("%d--",i);
                                }

                            }

                            printf("\nNolu odalar deluxe odalara dahildir, birini seciniz.");
                            scanf("%d",&odasecimi);

                            if(odasecimi%2!=0 || odasecimi%6==0 || odasecimi==0)
                            {
                                printf("\nSectiginiz oda deluxe odalara dahil degildir. Lutfen yeni oda seciniz.\n");
                                odasecimi2=0;

                            }
                            else if(odalar[odasecimi-1][hafta-1]==1)
                            {
                                printf("\nSectiginiz oda doludur lutfen baska oda seciniz.\n");
                                odasecimi2=0;
                            }
                            else
                            {
                                odasecimi2=1;
                            }
                        }
                        while(odasecimi2==0);
                        odalar[odasecimi-1][hafta-1]=1;
                        misafirsayaci-=4;
                        }
                        printf("\nLutfen odeme tipini seciniz.\nOn odemeli rezervasyon icin 'O'   Havale ile odeme icin 'H'   Standart odeme icin 'S' Tusuna basiniz.\t");
                        scanf(" %c",&odemetipi);
                        switch(odemetipi)
                        {
                            case 'O':
                            case 'o':
                                ucret=((misafirsayisi*75*7)-((misafirsayisi*75*7)*15/100));
                                printf("\nRezervasyon ucretiniz %d$ dir.",ucret);
                                printf("\nOtelimizdeki dolu odalarin yuzdesi:\n");
                                for(i=0; i<12; i++)
                                {
                                    for(j=0; j<100; j++)
                                    {
                                        if(odalar[j][i]==1)
                                        {
                                            yuzdesayaci++;
                                        }
                                    }
                                printf("%d. hafta icin  = %%%d dir.\n",i+1,yuzdesayaci);
                                yuzdesayaci=0;
                                }
                                printf("Baska rezervasyon yapmak ister misiniz\(E\\H)");
                                scanf(" %c", &devam);
                                break;
                                break;

                            case 'H':
                            case 'h':
                                if(misafirsayisi>5)
                                {
                                    ucret=(misafirsayisi*75*7)-(75*7*75/100);
                                }
                                else if(misafirsayisi>3)
                                {
                                    ucret=(misafirsayisi*75*7)-(75*7*50/100);
                                }
                                else
                                {
                                    ucret=misafirsayisi*75*7;
                                }
                                printf("\nRezervasyon ucretiniz %d$ dir.",ucret);
                                printf("\nOtelimizdeki dolu odalarin yuzdesi:\n");
                                for(i=0; i<12; i++)
                                {
                                    for(j=0; j<100; j++)
                                    {
                                        if(odalar[j][i]==1)
                                        {
                                            yuzdesayaci++;
                                        }
                                    }
                                printf("%d. hafta icin  = %%%d dir.\n",i+1,yuzdesayaci);
                                yuzdesayaci=0;
                                }
                                printf("Baska rezervasyon yapmak ister misiniz\(E\\H)");
                                scanf(" %c", &devam);
                                break;
                                break;

                            case 'S':
                            case 's':
                                ucret=misafirsayisi*75*7;
                                printf("\nRezervasyon ucretiniz %d$ dir.",ucret);
                                printf("\nOtelimizdeki dolu odalarin yuzdesi:\n");
                                for(i=0; i<12; i++)
                                {
                                    for(j=0; j<100; j++)
                                    {
                                        if(odalar[j][i]==1)
                                        {
                                            yuzdesayaci++;
                                        }
                                    }
                                printf("%d. hafta icin  = %%%d dir.\n",i+1,yuzdesayaci);
                                yuzdesayaci=0;
                                }
                                printf("Baska rezervasyon yapmak ister misiniz\(E\\H)");
                                scanf(" %c", &devam);
                                break;
                                break;
                        }

                        break;
                        break;

                    default:
                        printf("\nYanlis tusa bastiniz.");
                        break;

                }
                break;
                break;

            case 'Y':
            case 'y':


                for(i=0; i<3; i++)
                {
                    printf("\nYazin kacinci haftasinda konaklama yapilacagini giriniz\t");
                    scanf("%d",&hafta);
                    if(hafta<1 || hafta >12)
                    {
                        yanlisgirdi++;
                    }
                    else
                    {
                        break;
                    }
                }
                if(yanlisgirdi>=3)
                {
                    exit(0);
                }

                printf("\nLutfen oda tipini seciniz.\nStandart odalar icin 'S'   Large Deluxe odalar icin 'L'   Deluxe odalar icin 'D' tusuna basiniz");
                scanf(" %c",&odatipi);
                switch(odatipi)
                {
                    case 'S':
                    case 's':
                        do
                        {
                            for(i=1; i<=100; i++)
                            {
                                if(odalar[i-1][12+hafta-1]==0 && i%2==1)
                                {
                                    printf("%d--",i);
                                }

                            }

                            printf("\nNolu odalar standart odalara dahildir, birini seciniz.");
                            scanf("%d",&odasecimi);

                            if(odasecimi%2!=1)
                            {
                                printf("\nSectiginiz oda standart odalara dahil degildir. Lutfen yeni oda seciniz.\n");
                                odasecimi2=0;

                            }
                            else if(odalar[odasecimi-1][12+hafta-1] == 1 )
                            {
                                printf("\nSectiginiz oda doludur lutfen baska oda seciniz.\n");
                                odasecimi2=0;
                            }
                            else
                            {
                                odasecimi2=1;
                            }
                        }
                        while(odasecimi2==0);
                        odalar[odasecimi-1][12+hafta-1]=1;
                        do
                        {
                            printf("\nKalacak misafir sayisini giriniz.\t");
                            scanf("%d",&misafirsayisi);
                            if(misafirsayisi<=0)
                            {
                                printf("\nMisafir sayisi 0'dan kucuk olamaz. Lutfen tekrar deneyiniz.");
                                misafirdegeri=0;

                            }
                            else
                                misafirdegeri=1;
                        }
                        while(misafirdegeri==0);
                        misafirsayaci=misafirsayisi;
                        while(misafirsayaci>4)
                        {
                            printf("\nMisafir sayiniz oda kapasitesinden fazladir. Lutfen geriye kalan misafirleriniz icin yeni oda secin.\n");
                            do
                        {
                            for(i=1; i<=100; i++)
                            {
                                if(odalar[i-1][12+hafta-1]==0 && i%2==1)
                                {
                                    printf("%d--",i);
                                }

                            }

                            printf("\nNolu odalar standart odalara dahildir, birini seciniz.");
                            scanf("%d",&odasecimi);

                            if(odasecimi%2!=1)
                            {
                                printf("\nSectiginiz oda standart odalara dahil degildir. Lutfen yeni oda seciniz.\n");
                                odasecimi2=0;

                            }
                            else if(odalar[odasecimi-1][12+hafta-1] == 1 )
                            {
                                printf("\nSectiginiz oda doludur lutfen baska oda seciniz.\n");
                                odasecimi2=0;
                            }
                            else
                            {
                                odasecimi2=1;
                            }
                        }
                        while(odasecimi2==0);
                        odalar[odasecimi-1][12+hafta-1]=1;
                        misafirsayaci-=4;
                        }
                        printf("\nLutfen odeme tipini seciniz.\nOn odemeli rezervasyon icin 'O'   Havale ile odeme icin 'H'   Standart odeme icin 'S' Tusuna basiniz.\t");
                        scanf(" %c",&odemetipi);
                        switch(odemetipi)
                        {
                            case 'O':
                            case 'o':
                                ucret=((misafirsayisi*60*7)-((misafirsayisi*60*7)*15/100));
                                printf("\nRezervasyon ucretiniz %d$ dir.",ucret);
                                printf("\nOtelimizdeki dolu odalarin yuzdesi:\n");
                                for(i=12; i<24; i++)
                                {
                                    for(j=0; j<100; j++)
                                    {
                                        if(odalar[j][i]==1)
                                        {
                                            yuzdesayaci++;
                                        }
                                    }
                                printf("%d. hafta icin  = %%%d dir.\n",i-11,yuzdesayaci);
                                yuzdesayaci=0;
                                }
                                printf("Baska rezervasyon yapmak ister misiniz\(E\\H)");
                                scanf(" %c", &devam);

                                break;
                                break;

                            case 'H':
                            case 'h':
                                if(misafirsayisi>5)
                                {
                                    ucret=(misafirsayisi*60*7)-(60*7*75/100);
                                }
                                else if(misafirsayisi>3)
                                {
                                    ucret=(misafirsayisi*60*7)-(60*7*50/100);
                                }
                                else
                                {
                                    ucret=misafirsayisi*60*7;
                                }
                                printf("\nRezervasyon ucretiniz %d$ dir.",ucret);
                                printf("\nOtelimizdeki dolu odalarin yuzdesi:\n");
                                for(i=12; i<24; i++)
                                {
                                    for(j=0; j<100; j++)
                                    {
                                        if(odalar[j][i]==1)
                                        {
                                            yuzdesayaci++;
                                        }
                                    }
                                printf("%d. hafta icin  = %%%d dir.\n",i-11,yuzdesayaci);
                                yuzdesayaci=0;
                                }
                                printf("Baska rezervasyon yapmak ister misiniz\(E\\H)");
                                scanf(" %c", &devam);
                                break;
                                break;

                            case 'S':
                            case 's':
                                ucret=misafirsayisi*60*7;
                                printf("\nRezervasyon ucretiniz %d$ dir.",ucret);
                                printf("\nOtelimizdeki dolu odalarin yuzdesi:\n");
                                for(i=12; i<24; i++)
                                {
                                    for(j=0; j<100; j++)
                                    {
                                        if(odalar[j][i]==1)
                                        {
                                            yuzdesayaci++;
                                        }
                                    }
                                printf("%d. hafta icin  = %%%d dir.\n",i-11,yuzdesayaci);
                                yuzdesayaci=0;
                                }
                                printf("\nBaska rezervasyon yapmak ister misiniz\(E\\H)");
                                scanf(" %c", &devam);
                                break;
                                break;

                            default:
                                printf("\nYanlis tusa bastiniz.");
                                break;


                        }

                        break;
                        break;

                    case 'L':
                    case 'l':

                        do
                        {
                            for(i=1; i<=100; i++)
                            {
                                if(odalar[i-1][12+hafta-1]==0 && i%2==0 && i%6==0)
                                {
                                    printf("%d--",i);
                                }

                            }

                            printf("\nNolu odalar large deluxe odalara dahildir, birini seciniz.");
                            scanf("%d",&odasecimi);

                            if(odasecimi%2!=0 || odasecimi%6!=0 || odasecimi==0)
                            {
                                printf("\nSectiginiz oda large deluxe odalara dahil degildir. Lutfen yeni oda seciniz.\n");
                                odasecimi2=0;

                            }
                            else if(odalar[odasecimi-1][12+hafta-1]==1)
                            {
                                printf("\nSectiginiz oda doludur lutfen baska oda seciniz.\n");
                                odasecimi2=0;
                            }
                            else
                            {
                                odasecimi2=1;
                            }
                        }
                        while(odasecimi2==0);
                        odalar[odasecimi-1][12+hafta-1]=1;
                        odasayaci++;

                       do
                        {
                            printf("\nKalacak misafir sayisini giriniz.\t");
                            scanf("%d",&misafirsayisi);
                            if(misafirsayisi<=0)
                            {
                                printf("\nMisafir sayisi 0'dan kucuk olamaz. Lutfen tekrar deneyiniz.");
                                misafirdegeri=0;

                            }
                            else
                                misafirdegeri=1;
                        }
                        while(misafirdegeri==0);
                        misafirsayaci=misafirsayisi;

                        while(misafirsayaci>7)
                        {
                            printf("\nMisafir sayiniz oda kapasitesinden fazladir. Lutfen geriye kalan misafirleriniz icin yeni oda secin.\n");
                            do
                        {
                            for(i=1; i<=100; i++)
                            {
                                if(odalar[i-1][12+hafta-1]==0 && i%2==0 && i%6==0)
                                {
                                    printf("%d--",i);
                                }

                            }

                            printf("\nNolu odalar large deluxe odalara dahildir, birini seciniz.");
                            scanf("%d",&odasecimi);

                            if(odasecimi%2!=0 || odasecimi%6!=0 || odasecimi==0)
                            {
                                printf("\nSectiginiz oda large deluxe odalara dahil degildir. Lutfen yeni oda seciniz.\n");
                                odasecimi2=0;

                            }
                            else if(odalar[odasecimi-1][12+hafta-1]==1)
                            {
                                printf("\nSectiginiz oda doludur lutfen baska oda seciniz.\n");
                                odasecimi2=0;
                            }
                            else
                            {
                                odasecimi2=1;
                            }
                        }
                        while(odasecimi2==0);
                        odalar[odasecimi-1][12+hafta-1]=1;
                        odasayaci++;
                        misafirsayaci-=7;
                        }
                        printf("\nLutfen odeme tipini seciniz.\nOn odemeli rezervasyon icin 'O'   Havale ile odeme icin 'H'   Standart odeme icin 'S' Tusuna basiniz.\t");
                        scanf(" %c",&odemetipi);
                        switch(odemetipi)
                        {
                            case 'O':
                            case 'o':
                                ucret=odasayaci*((400*7)-(400*7*15/100));
                                printf("\nRezervasyon ucretiniz %d$ dir.",ucret);
                                printf("\nOtelimizdeki dolu odalarin yuzdesi:\n");
                                for(i=12; i<24; i++)
                                {
                                    for(j=0; j<100; j++)
                                    {
                                        if(odalar[j][i]==1)
                                        {
                                            yuzdesayaci++;
                                        }
                                    }
                                printf("%d. hafta icin  = %%%d dir.\n",i-12,yuzdesayaci);
                                yuzdesayaci=0;
                                }
                                printf("Baska rezervasyon yapmak ister misiniz\(E\\H)");
                                scanf(" %c", &devam);

                                break;
                                break;

                            case 'H':
                            case 'h':
                                ucret=400*7*odasayaci;
                                printf("\nRezervasyon ucretiniz %d$ dir.",ucret);
                                printf("\nOtelimizdeki dolu odalarin yuzdesi:\n");
                                for(i=12; i<24; i++)
                                {
                                    for(j=0; j<100; j++)
                                    {
                                        if(odalar[j][i]==1)
                                        {
                                            yuzdesayaci++;
                                        }
                                    }
                                printf("%d. hafta icin  = %%%d dir.\n",i-11,yuzdesayaci);
                                yuzdesayaci=0;
                                }
                                printf("Baska rezervasyon yapmak ister misiniz\(E\\H)");
                                scanf(" %c", &devam);
                                break;
                                break;

                            case 'S':
                            case 's':
                                ucret=400*7*odasayaci;
                                printf("\nRezervasyon ucretiniz %d$ dir.",ucret);
                                printf("\nOtelimizdeki dolu odalarin yuzdesi:\n");
                                for(i=12; i<24; i++)
                                {
                                    for(j=0; j<100; j++)
                                    {
                                        if(odalar[j][i]==1)
                                        {
                                            yuzdesayaci++;
                                        }
                                    }
                                printf("%d. hafta icin  = %%%d dir.\n",i-11,yuzdesayaci);
                                yuzdesayaci=0;
                                }
                                printf("\nBaska rezervasyon yapmak ister misiniz\(E\\H)");
                                scanf(" %c", &devam);
                                break;
                                break;

                            default:
                                printf("\nYanlis tusa bastiniz.");
                                break;


                        }
                        break;
                        break;

                    case 'D':
                    case 'd':
                        do
                        {
                            for(i=1; i<=100; i++)
                            {
                                if(odalar[i-1][12+hafta-1]==0 && i%2==0)
                                {
                                    if(i%6==0)
                                    {
                                        continue;
                                    }
                                    printf("%d--",i);
                                }

                            }

                            printf("\nNolu odalar deluxe odalara dahildir, birini seciniz.");
                            scanf("%d",&odasecimi);

                            if(odasecimi%2!=0 || odasecimi%6==0 || odasecimi==0)
                            {
                                printf("\nSectiginiz oda deluxe odalara dahil degildir. Lutfen yeni oda seciniz.\n");
                                odasecimi2=0;

                            }
                            else if(odalar[odasecimi-1][12+hafta-1]==1)
                            {
                                printf("\nSectiginiz oda doludur lutfen baska oda seciniz.\n");
                                odasecimi2=0;
                            }
                            else
                            {
                                odasecimi2=1;
                            }
                        }
                        while(odasecimi2==0);
                        odalar[odasecimi-1][12+hafta-1]=1;
                        do
                        {
                            printf("\nKalacak misafir sayisini giriniz.\t");
                            scanf("%d",&misafirsayisi);
                            if(misafirsayisi<=0)
                            {
                                printf("\nMisafir sayisi 0'dan kucuk olamaz. Lutfen tekrar deneyiniz.");
                                misafirdegeri=0;

                            }
                            else
                                misafirdegeri=1;
                        }
                        while(misafirdegeri==0);
                        misafirsayaci=misafirsayisi;
                        while(misafirsayaci>4)
                        {
                            printf("\nMisafir sayiniz oda kapasitesinden fazladir. Lutfen geriye kalan misafirleriniz icin yeni oda secin.\n");
                            do
                        {
                            for(i=1; i<=100; i++)
                            {
                                if(odalar[i-1][12+hafta-1]==0 && i%2==0)
                                {
                                    if(i%6==0)
                                    {
                                        continue;
                                    }
                                    printf("%d--",i);
                                }

                            }

                            printf("\nNolu odalar deluxe odalara dahildir, birini seciniz.");
                            scanf("%d",&odasecimi);

                            if(odasecimi%2!=0 || odasecimi%6==0 || odasecimi==0)
                            {
                                printf("\nSectiginiz oda deluxe odalara dahil degildir. Lutfen yeni oda seciniz.\n");
                                odasecimi2=0;

                            }
                            else if(odalar[odasecimi-1][12+hafta-1]==1)
                            {
                                printf("\nSectiginiz oda doludur lutfen baska oda seciniz.\n");
                                odasecimi2=0;
                            }
                            else
                            {
                                odasecimi2=1;
                            }
                        }
                        while(odasecimi2==0);
                        odalar[odasecimi-1][12+hafta-1]=1;
                        misafirsayaci-=4;
                        }
                        printf("\nLutfen odeme tipini seciniz.\nOn odemeli rezervasyon icin 'O'   Havale ile odeme icin 'H'   Standart odeme icin 'S' Tusuna basiniz.\t");
                        scanf(" %c",&odemetipi);
                        switch(odemetipi)
                        {
                            case 'O':
                            case 'o':
                                ucret=((misafirsayisi*90*7)-((misafirsayisi*90*7)*15/100));
                                printf("\nRezervasyon ucretiniz %d$ dir.",ucret);
                                printf("\nOtelimizdeki dolu odalarin yuzdesi:\n");
                                for(i=12; i<24; i++)
                                {
                                    for(j=0; j<100; j++)
                                    {
                                        if(odalar[j][i]==1)
                                        {
                                            yuzdesayaci++;
                                        }
                                    }
                                printf("%d. hafta icin  = %%%d dir.\n",i-11,yuzdesayaci);
                                yuzdesayaci=0;
                                }
                                printf("Baska rezervasyon yapmak ister misiniz\(E\\H)");
                                scanf(" %c", &devam);
                                break;
                                break;

                            case 'H':
                            case 'h':
                                if(misafirsayisi>5)
                                {
                                    ucret=(misafirsayisi*90*7)-(90*7*75/100);
                                }
                                else if(misafirsayisi>3)
                                {
                                    ucret=(misafirsayisi*90*7)-(90*7*50/100);
                                }
                                else
                                {
                                    ucret=misafirsayisi*90*7;
                                }
                                printf("\nRezervasyon ucretiniz %d$ dir.",ucret);
                                printf("\nOtelimizdeki dolu odalarin yuzdesi:\n");
                                for(i=12; i<24; i++)
                                {
                                    for(j=0; j<100; j++)
                                    {
                                        if(odalar[j][i]==1)
                                        {
                                            yuzdesayaci++;
                                        }
                                    }
                                printf("%d. hafta icin  = %%%d dir.\n",i-11,yuzdesayaci);
                                yuzdesayaci=0;
                                }
                                printf("Baska rezervasyon yapmak ister misiniz\(E\\H)");
                                scanf(" %c", &devam);
                                break;
                                break;

                            case 'S':
                            case 's':
                                ucret=misafirsayisi*90*7;
                                printf("\nRezervasyon ucretiniz %d$ dir.",ucret);
                                printf("\nOtelimizdeki dolu odalarin yuzdesi:\n");
                                for(i=12; i<24; i++)
                                {
                                    for(j=0; j<100; j++)
                                    {
                                        if(odalar[j][i]==1)
                                        {
                                            yuzdesayaci++;
                                        }
                                    }
                                printf("%d. hafta icin  = %%%d dir.\n",i-11,yuzdesayaci);
                                yuzdesayaci=0;
                                }
                                printf("Baska rezervasyon yapmak ister misiniz\(E\\H)");
                                scanf(" %c", &devam);
                                break;
                                break;
                        }

                        break;
                        break;

                    default:
                        printf("\nYanlis tusa bastiniz.");
                        break;

                }
                break;
                break;

            default:
                printf("\nYanlis tusa bastiniz.");
                break;


        }
        if(devam=='e')
        {
            devam='E';
        }
    }
    while(devam=='E');

    return 0;
}

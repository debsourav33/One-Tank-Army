    #include<stdio.h>
    #include<graphics.h>
    #include<iostream>
    #include<math.h>
    using namespace std;
int main()
{
    int gd=DETECT, gm, j=0,i=0, page=0, y=450, pot=1, cpflag=2, obhigh=150, lvlhigh=130, lvlgdhigh=170, hatch=0, scrboss=0, cphigh=130, bullety=145, gdhigh=90, alo=1, DanBam=200, potaka2=1, check2=1, imageX=115, fat=1500, helipot=0, shuru=100, height=900,flag=0, hov=0, tankX=43,tankY=605, obspeed=20, gdspeed=30, lvlspeed= 20, lvlgdspeed=25, cpspeed=13, potaka=0, check=0, durotto=170;

   // initgraph(&gd,&gm,"C:\\TC\\BGI");

    DWORD screenWidth = GetSystemMetrics(SM_CXSCREEN);
    DWORD screenHeight = GetSystemMetrics(SM_CYSCREEN);

    int dhakka=screenWidth, gddhakka=screenWidth+200, cpdhakka=screenWidth+350, lvlgddhakka=screenWidth+200, lvldhakka=screenWidth+80;

    initwindow(screenWidth,screenHeight,"",-3,-3);


    POINT curpos;


//cout<<screenHeight<<"  "<<screenWidth<<endl;

    while(1)
    {
    setactivepage(page);
    setvisualpage(1-page);

    readimagefile("menuback.jpg",0,0,screenWidth,screenHeight);




      //readimagefile("newgame.gif",400,100,800,500);
       //readimagefile("newgame.gif",400,100,800,500);
       if(GetAsyncKeyState(VK_DOWN))
          {
              hov++;
          }

        if(GetAsyncKeyState(VK_UP))
          {
              hov--;
          }

        if(GetAsyncKeyState(VK_RETURN)&&hov%3==0)
          {
              break;
          }

         if(GetAsyncKeyState(VK_RETURN)&&hov%3==2)
          {
              closegraph();
          }

        if(hov%3==0) readimagefile("newgamehov.gif",400,100,800,500);
        if(hov%3==1) readimagefile("helphov.gif",400,220,800,670);
        if(hov%3==2)  readimagefile("exithov.gif",400,360,800,815);


        if(hov%3!=0) readimagefile("newgame.gif",400,100,800,500);
        if(hov%3!=1) readimagefile("help.gif",400,220,800,670);
        if(hov%3!=2) readimagefile("exit.gif",400,360,800,815);

    page=1-page;
    }


    while(1)

  {
            setvisualpage(1-page);
            setactivepage(page);
         //   cleardevice();

            mciSendString("play backmusic.wav",0,0,0);


            int din=alo%100;

            scrboss=hatch+potaka;



            readimagefile("n8background.jpg",0,0,screenWidth,screenHeight);

            /*if(din>=0||din<10) {setvisualpage(page); readimagefile("background1.jpg",0,0,screenWidth,screenHeight);}
            if(din>=10||din<20) {setvisualpage(page); readimagefile("background2.jpg",0,0,screenWidth,screenHeight);}
            if(din>=20||din<30) {setvisualpage(page); readimagefile("background3.jpg",0,0,screenWidth,screenHeight);}
            if(din>=30||din<40) {setvisualpage(page); readimagefile("background4.jpg",0,0,screenWidth,screenHeight);}
            if(din>=40||din<50) {setvisualpage(page); readimagefile("background5.jpg",0,0,screenWidth,screenHeight);}
            if(din>=50||din<60) {setvisualpage(page); readimagefile("background4.jpg",0,0,screenWidth,screenHeight);}
            if(din>=60||din<70) {setvisualpage(page); readimagefile("background3.jpg",0,0,screenWidth,screenHeight);}
            if(din>=70||din<80) {setvisualpage(page); readimagefile("background2.jpg",0,0,screenWidth,screenHeight);}
            if(din>=80||din<90) {setvisualpage(page); readimagefile("background1.jpg",0,0,screenWidth,screenHeight);}
            if(din>=90||din<100) {setvisualpage(page); readimagefile("background1.jpg",0,0,screenWidth,screenHeight);}*/




            //readimagefile("sun2.gif",50,25,125,115);
            readimagefile("newtank2.gif",tankX,tankY,tankX+260,tankY+194);

            y=pow(i-height,2)/fat+shuru;

            if(flag==1)
            {
                i+=50; //speed
                 imageX=i+DanBam; //imageX holo shell er initial X
                 readimagefile("fire 2.gif",imageX,y,imageX+19,y+19);
            }




            if(y>650)
            {
                  readimagefile("n8background.jpg",0,0,screenWidth,screenHeight);
                  readimagefile("newtank2.gif",tankX,tankY,tankX+260,tankY+194);
                  flag=0;
            }



           // delay(5);

            if (kbhit() && flag==0)
           {
               if(GetAsyncKeyState(VK_RIGHT))
               {
                   delay(500);
                    DanBam+=40;
                    tankX+=40;
                   readimagefile("n8background.jpg",0,0,screenWidth,screenHeight);
                   readimagefile("tankmove.gif",tankX,tankY,tankX+260,tankY+194);
               }

                if(GetAsyncKeyState(VK_LEFT))
                {
                 delay(500);
                   DanBam-=40;
                   tankX-=40;
                   readimagefile("n8background.jpg",0,0,screenWidth,screenHeight);
                   readimagefile("tankmove.gif",tankX,tankY,tankX+260,tankY+194);
                }



              /* if(GetAsyncKeyState(VK_UP))
               {
                   delay(500);
                     fat-=200;
               }

                if(GetAsyncKeyState(VK_DOWN))
                {
                    delay(500);
                     fat+=200;
                }*/

           }



        if(GetAsyncKeyState(VK_SPACE))
        {
            pot=1;
            if(y>600){
             mciSendString("play expshell2.mp3",0,0,0);
             readimagefile("n8background.jpg",0,0,screenWidth,screenHeight);
             readimagefile("newtank2.gif",tankX-2,tankY+1,tankX+260-2,tankY+194+1);
             flag=1;

             i=0;
            }

        }


       // cout<<fat<<" "<<DanBam<<endl;

    //    cleardevice();


        setcolor(BLACK);


        //mciSendString("play chop.mp3",0,0,0);


         if(scrboss==5)
            {
                setvisualpage(page);

                mciSendString("play epicboss.mp3",0,0,0);
                readimagefile("comm.jpg",0,0,screenWidth,screenHeight);



                hatch++;

                delay(6800);

            }


        //Period Of Chopper Invaders
        if(potaka>=5){
            //mciSendString("play machine.mp3",0,0,0);
            //mciSendString("play boss.mp3",0,0,0);
            if((cpdhakka<2000)&&(cpdhakka>0)){
            readimagefile("bullet.gif",cpdhakka+40,bullety,cpdhakka+130,bullety+70);
            bullety=bullety+16;
            if(bullety>1200){
                bullety=145;
                mciSendString("play plane.mp3",0,0,0);
            }
            }


            if(cpflag==2)
            readimagefile("heli.gif",cpdhakka,cphigh,cpdhakka+250,cphigh+95);
            if(cpflag==1)
            readimagefile("heli180.gif",cpdhakka,cphigh,cpdhakka+250,cphigh+95);

            if(cpflag==2)
            cpdhakka=cpdhakka-cpspeed;
            if(cpflag==1)
            cpdhakka=cpdhakka+cpspeed;

            if(cpdhakka<100)
                cpflag=1;
            if(cpdhakka>=screenWidth-300)
                cpflag=2;

            if((imageX-cpdhakka>=-40&&imageX-cpdhakka<=240)&&(y-cphigh<=60&&y-cphigh>=10)){

                readimagefile("explode.gif",cpdhakka+60,cphigh-40,cpdhakka+160,cphigh+103);
                mciSendString("play heliex.wav",0,0,0);
                helipot++;
                i=0;
                flag=0;

                if(helipot>=5)
                    break;

            }

        }

          //Period of Plane Invaders
        if(potaka<5){


        readimagefile("newplane.gif",dhakka,obhigh,dhakka+150,obhigh+75);

        readimagefile("goodplane2.gif",gddhakka,gdhigh,gddhakka+130,gdhigh+80);



        dhakka=dhakka-obspeed;

        gddhakka=gddhakka-gdspeed;


        if(dhakka<-100){
            dhakka=2500;
            potaka++;

            if(potaka%4==1) {dhakka=2000; obspeed=18; obhigh=70;}
            if(potaka%4==2) {dhakka=1900; obspeed=16; obhigh=160;}
            if(potaka%4==3) {dhakka=1800; obspeed=12; obhigh=80;}
            if(potaka%4==0) {dhakka=2200; obspeed=19; obhigh=200;}


        }


        if(gddhakka<-100){

            gddhakka=2100;
            potaka2++;

            if(potaka2%4==1) {gddhakka=2200; gdspeed=18; gdhigh=50;}
            if(potaka2%4==2) {gddhakka=1700; gdspeed=16; gdhigh=180;}
            if(potaka2%4==3) {gddhakka=1900; gdspeed=12; gdhigh=90;}
            if(potaka2%4==0) {gddhakka=2000; gdspeed=19; gdhigh=170;}
        }

        setcolor(WHITE);
        if(potaka==0)
        outtextxy(20,20,"Score: O");
        if(potaka==1)
        outtextxy(20,20,"Score: I");
        if(potaka==2)
        outtextxy(20,20,"Score II");
        if(potaka==3)
        outtextxy(20,20,"Score III");
        if(potaka==4)
        outtextxy(20,20,"Score IV");
        if(potaka==5)
        outtextxy(20,20,"Score V");

        if((imageX-dhakka>=-40&&imageX-dhakka<=80)&&(y-obhigh<=60&&y-obhigh>=-05))
            {
            //readimagefile("newplanecrush.gif",dhakka,obhigh,dhakka+150,obhigh+75);




            readimagefile("explode.gif",dhakka,obhigh-40,dhakka+150,obhigh+100);
            mciSendString("play COLL.mp3",0,0,0);

            delay(550);
            potaka++;
            i=0;
            flag=0;

            if(potaka%4==1) {dhakka=2000; obspeed=18; obhigh=70;}
            if(potaka%4==2) {dhakka=1900; obspeed=16; obhigh=160;}
            if(potaka%4==3) {dhakka=1800; obspeed=12; obhigh=80;}
            if(potaka%4==0) {dhakka=2200; obspeed=19; obhigh=200;}

            }




        if((imageX-gddhakka>=-60&&imageX-gddhakka<=80)&&(y-gdhigh<=60&&y-gdhigh>=-10))
            {
            //readimagefile("newplanecrush.gif",dhakka,obhigh,dhakka+150,obhigh+75);




            readimagefile("explode.gif",gddhakka,gdhigh-40,gddhakka+150,gdhigh+100);
            mciSendString("play COLL.mp3",0,0,0);

            potaka2++;
            i=0;
            flag=0;

            if(potaka2%4==1) {gddhakka=2200; gdspeed=18; gdhigh=50;}
            if(potaka2%4==2) {gddhakka=1700; gdspeed=16; gdhigh=180;}
            if(potaka2%4==3) {gddhakka=1900; gdspeed=12; gdhigh=90;}
            if(potaka2%4==0) {gddhakka=2000; gdspeed=19; gdhigh=170;}

            }
    }





        page=1-page;
        alo++;

    }

    cleardevice();
    setvisualpage(page);
    readimagefile("lvl2.jpg",0,0,screenWidth,screenHeight);
    delay(5000);

    cpdhakka=screenWidth+350, cpflag=2;

     while(1)

  {
            setvisualpage(1-page);
            setactivepage(page);
         //   cleardevice();

            mciSendString("play backmusic.wav",0,0,0);


            int din=alo%100;


            scrboss=hatch+potaka;



            readimagefile("ntbackground.jpg",0,0,screenWidth,screenHeight);



            //readimagefile("sun2.gif",50,25,125,115);
            readimagefile("canontank.gif",tankX,tankY,tankX+220,tankY+195);

            y=pow(i-height,2)/fat+shuru;

            if(flag==1)
            {
                i+=50; //speed
                 imageX=i+DanBam; //imageX holo shell er initial X
                 readimagefile("fire 2.gif",imageX,y,imageX+19,y+19);
            }




            if(y>650)
            {
                  readimagefile("ntbackground.jpg",0,0,screenWidth,screenHeight);
                  readimagefile("canontank.gif",tankX,tankY,tankX+220,tankY+195);
                  flag=0;
            }



           // delay(5);

            if (kbhit() && flag==0)
           {
               if(GetAsyncKeyState(VK_RIGHT))
               {
                   delay(500);
                    DanBam+=40;
                    tankX+=40;
                   readimagefile("ntbackground.jpg",0,0,screenWidth,screenHeight);
                   readimagefile("canontank.gif",tankX,tankY,tankX+220,tankY+195);
               }

                if(GetAsyncKeyState(VK_LEFT))
                {
                 delay(500);
                   DanBam-=40;
                   tankX-=40;
                   readimagefile("ntbackground.jpg",0,0,screenWidth,screenHeight);
                   readimagefile("canontank.gif",tankX,tankY,tankX+220,tankY+195);
                }



              /* if(GetAsyncKeyState(VK_UP))
               {
                   delay(500);
                     fat-=200;
               }

                if(GetAsyncKeyState(VK_DOWN))
                {
                    delay(500);
                     fat+=200;
                }*/

           }



        if(GetAsyncKeyState(VK_SPACE))
        {
            pot=1;
            if(y>600){
             mciSendString("play expshell2.mp3",0,0,0);
             readimagefile("ntbackground.jpg",0,0,screenWidth,screenHeight);
             readimagefile("canontank.gif",tankX-2,tankY+1,tankX+220-2,tankY+195+1);
             flag=1;

             i=0;
            }

        }


       // cout<<fat<<" "<<DanBam<<endl;

    //    cleardevice();


        setcolor(BLACK);


        //mciSendString("play chop.mp3",0,0,0);


         /*if(scrboss==5)
            {
                setvisualpage(page);

                mciSendString("play epicboss.mp3",0,0,0);
                readimagefile("scrboss.jpg",0,0,screenWidth,screenHeight);



                hatch++;

                delay(5000);

            }*/


        //Period Of Chopper Invaders
        if(check>=5){
            //mciSendString("play machine.mp3",0,0,0);
            //mciSendString("play boss.mp3",0,0,0);
            if((cpdhakka<2000)&&(cpdhakka>0)){
            readimagefile("bullet.gif",cpdhakka+40,bullety,cpdhakka+130,bullety+70);
            bullety=bullety+16;
            if(bullety>1200){
                bullety=145;
                mciSendString("play plane.mp3",0,0,0);
            }
            }


            if(cpflag==2)
            readimagefile("newboss2.gif",cpdhakka,cphigh,cpdhakka+250,cphigh+125);
            if(cpflag==1)
            readimagefile("newboss2180.gif",cpdhakka,cphigh,cpdhakka+250,cphigh+125);

            if(cpflag==2)
            cpdhakka=cpdhakka-cpspeed;
            if(cpflag==1)
            cpdhakka=cpdhakka+cpspeed;

            if(cpdhakka<100)
                cpflag=1;
            if(cpdhakka>=screenWidth-300)
                cpflag=2;

            if((imageX-cpdhakka>=-40&&imageX-cpdhakka<=240)&&(y-cphigh<=60&&y-cphigh>=10)){

                readimagefile("explode.gif",cpdhakka+60,cphigh-40,cpdhakka+160,cphigh+103);
                mciSendString("play heliex.wav",0,0,0);
                helipot++;
                i=0;
                flag=0;

                if(helipot>=5)
                    break;

            }

        }

          //Period of Plane Invaders
        if(check<5){


        /*readimagefile("lvlplane.gif",lvldhakka,lvlhigh,lvldhakka+150,lvlhigh+72);

        readimagefile("lvlgdplane.gif",lvlgddhakka,lvlgdhigh,lvlgddhakka+150,lvlgdhigh+72);*/

        readimagefile("newplane.gif",lvldhakka,lvlhigh,lvldhakka+150,lvlhigh+75);

        readimagefile("goodplane2.gif",lvlgddhakka,lvlgdhigh,lvlgddhakka+140,lvlgdhigh+82);



        lvldhakka=lvldhakka-lvlspeed;

        lvlgddhakka=lvlgddhakka-lvlgdspeed;


        if(lvldhakka<-100){
            lvldhakka=2500;
            check++;

            if(check%4==1) {dhakka=2000; obspeed=18; obhigh=70;}
            if(check%4==2) {dhakka=1900; obspeed=16; obhigh=160;}
            if(check%4==3) {dhakka=1800; obspeed=12; obhigh=80;}
            if(check%4==0) {dhakka=2200; obspeed=19; obhigh=200;}


        }


        if(lvlgddhakka<-100){

            lvlgddhakka=2100;
            check2++;

            if(check2%4==1) {lvlgddhakka=2200; lvlgdspeed=18; lvlgdhigh=50;}
            if(check2%4==2) {lvlgddhakka=1700; lvlgdspeed=16; lvlgdhigh=180;}
            if(check2%4==3) {lvlgddhakka=1900; lvlgdspeed=12; lvlgdhigh=90;}
            if(check2%4==0) {lvlgddhakka=2000; lvlgdspeed=19; lvlgdhigh=170;}
        }

        setcolor(WHITE);
        if(check==0)
        outtextxy(20,20,"Score: O");
        if(check==1)
        outtextxy(20,20,"Score: I");
        if(check==2)
        outtextxy(20,20,"Score II");
        if(check==3)
        outtextxy(20,20,"Score III");
        if(check==4)
        outtextxy(20,20,"Score IV");
        if(check==5)
        outtextxy(20,20,"Score V");

        if((imageX-lvldhakka>=-40&&imageX-lvldhakka<=80)&&(y-lvlhigh<=60&&y-lvlhigh>=-05))
            {
            //readimagefile("newplanecrush.gif",dhakka,obhigh,dhakka+150,obhigh+75);




            readimagefile("explode.gif",lvldhakka,lvlhigh-40,lvldhakka+150,lvlhigh+100);
            mciSendString("play COLL.mp3",0,0,0);

            delay(550);
            check++;
            i=0;
            flag=0;

            if(check%4==1) {lvldhakka=2000; lvlspeed=18; lvlhigh=70;}
            if(check%4==2) {lvldhakka=1900; lvlspeed=16; lvlhigh=160;}
            if(check%4==3) {lvldhakka=1800; lvlspeed=12; lvlhigh=80;}
            if(check%4==0) {lvldhakka=2200; lvlspeed=19; lvlhigh=200;}

            }




        if((imageX-lvlgddhakka>=-60&&imageX-lvlgddhakka<=80)&&(y-lvlgdhigh<=60&&y-lvlgdhigh>=-10))
            {
            //readimagefile("newplanecrush.gif",dhakka,obhigh,dhakka+150,obhigh+75);




            readimagefile("explode.gif",lvlgddhakka,lvlgdhigh-40,lvlgddhakka+150,lvlgdhigh+100);
            mciSendString("play COLL.mp3",0,0,0);

            check2++;
            i=0;
            flag=0;

            if(check2%4==1) {lvlgddhakka=2200; lvlgdspeed=18; lvlgdhigh=50;}
            if(check%4==2) {lvlgddhakka=1700; lvlgdspeed=16; lvlgdhigh=180;}
            if(check2%4==3) {lvlgddhakka=1900; lvlgdspeed=12; lvlgdhigh=90;}
            if(check2%4==0) {lvlgddhakka=2000; lvlgdspeed=19; lvlgdhigh=170;}

            }
    }


        page=1-page;
        alo++;

    }

    getch();
    closegraph();

    return 0;
}

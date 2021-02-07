    #include<stdio.h>
    #include<graphics.h>
    #include<iostream>
    #include<math.h>
    using namespace std;

int life=0, scr=0, page=0, hov=0, help=0;
char s[100000];

    DWORD screenWidth = GetSystemMetrics(SM_CXSCREEN);
    DWORD screenHeight = GetSystemMetrics(SM_CYSCREEN);

    int sW=screenWidth, sH=screenHeight;


void score(int scr)
{
    setcolor(WHITE);
    if(scr<0)
    sprintf(s,"Score: %d",0);
    else
    sprintf(s,"Score: %d",scr);
    settextstyle(BOLD_FONT,HORIZ_DIR,2);
    outtextxy(19,19,s);
}


void finalscore(int scr)
{
    setcolor(WHITE);
    if(scr<0)
    sprintf(s,"Your Score is: %d",0);
    else
    sprintf(s,"Your Score is: %d",scr);
    settextstyle(BOLD_FONT,HORIZ_DIR,2);
    outtextxy(sW/2-100,sH-150,s);
}

void lives(int life)
{
    if(life==0)
        readimagefile("hfull1.gif",screenWidth-200,16,screenWidth-20,48);
    if(life==1)
        readimagefile("hfull2.gif",screenWidth-200,16,screenWidth-20,48);
    if(life==2)
        readimagefile("hfull3.gif",screenWidth-200,16,screenWidth-20,48);
}
int main()
{
    starts: int gd=DETECT, gm, j=0,i=0, page=0, y= 450,  pot=1, cpflag=2, obhigh=170, lvlhigh=90, lvlgdhigh=150, hatch=0, scrboss=0, cphigh=sH/6-25, bullety=cphigh+20, gdhigh=80, alo=1, DanBam=200, potaka2=1, check2=1, imageX=90, fat=1500, helipot=0, shuru=100, height=900,flag=0, hov=0, tankX=45,tankY=sH-247, obspeed=18, gdspeed=27, lvlspeed= 20, lvlgdspeed=25, cpspeed=13, potaka=0, check=0, durotto=170;
            life=0;
   // initgraph(&gd,&gm,"C:\\TC\\BGI");

    DWORD screenWidth = GetSystemMetrics(SM_CXSCREEN);
    DWORD screenHeight = GetSystemMetrics(SM_CYSCREEN);


    printf("%d %d",sW,sH);

    int dhakka=screenWidth, gddhakka=screenWidth+200, cpdhakka=screenWidth+350, lvlgddhakka=screenWidth+100, lvldhakka=screenWidth+450, bulletx=cpdhakka+50, enemy=0;

    initwindow(sW,sH,"",-3,-3);


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

        if(GetAsyncKeyState(VK_RETURN)&&hov%4==0)
          {
              break;
          }
        if(GetAsyncKeyState(VK_RETURN)&&hov%4==1)
          {

              while(1)
              {
                  if(GetAsyncKeyState(VK_SPACE))
                  help++;
                  setvisualpage(page);
                  if(help%4==0)
                  readimagefile("story.jpg",0,0,screenWidth,screenHeight);
                  if(help%4==1)
                  readimagefile("story2.jpg",0,0,screenWidth,screenHeight);
                  if(help%4==2)
                  readimagefile("story3.jpg",0,0,screenWidth,screenHeight);
                  if(help%4==3)
                  readimagefile("story4.jpg",0,0,screenWidth,screenHeight);

                  if(GetAsyncKeyState(VK_ESCAPE)){
                      delay(1000);
                      break;
                  }
              }
          }
          if(GetAsyncKeyState(VK_RETURN)&&hov%4==2)
          {

              while(1)
              {
                  if(GetAsyncKeyState(VK_ESCAPE))
                    break;
                  setvisualpage(page);

                  readimagefile("credits.jpg",0,0,screenWidth,screenHeight);
              }
          }


         if(GetAsyncKeyState(VK_RETURN)&&hov%4==3)
          {
              closegraph();
          }
        readimagefile("menuback.jpg",0,0,screenWidth,screenHeight);

        if(hov%4==0) readimagefile("newgamehov.gif",405,100,800,500);
        if(hov%4==1) readimagefile("helphov.gif",400,225,800,625);
        if(hov%4==2) readimagefile("credits2hov.gif",392,350,792,750);
        if(hov%4==3) readimagefile("exithov.gif",396,475,790,875);


        if(hov%4!=0) readimagefile("newgame.gif",405,100,800,500);
        if(hov%4!=1) readimagefile("help.gif",400,225,800,625);
        if(hov%4!=2) readimagefile("credits2.gif",392,350,792,750);
        if(hov%4!=3) readimagefile("exit.gif",396,475,790,875);


    page=1-page;
    }


    while(1)

  {

            setvisualpage(1-page);
            setactivepage(page);
         //   cleardevice();


            mciSendString("play backmusic.wav",0,0,0);

            setcolor(YELLOW);


            readimagefile("background.jpg",0,0,screenWidth,screenHeight);
            score(scr);
            lives(life);




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
                  readimagefile("background.jpg",0,0,screenWidth,screenHeight);
                  lives(life);
                  score(scr);
                  readimagefile("canontank.gif",tankX,tankY,tankX+220,tankY+195);
                  flag=0;
            }



           // delay(5);

            if (kbhit() && flag==0)
           {
               if(GetAsyncKeyState(VK_RIGHT))
               {
                   delay(500);
                   if(tankX<sW-250){
                        DanBam+=40;
                        tankX+=40;
                   }
                   readimagefile("background.jpg",0,0,screenWidth,screenHeight);
                   lives(life);
                   score(scr);
                   readimagefile("canontank.gif",tankX,tankY,tankX+220,tankY+195);
               }

                if(GetAsyncKeyState(VK_LEFT))
                {
                 delay(500);
                 if(tankX>0){
                       DanBam-=40;
                       tankX-=40;
                    }
                   readimagefile("background.jpg",0,0,screenWidth,screenHeight);
                   lives(life);
                   score(scr);
                   readimagefile("canontank.gif",tankX,tankY,tankX+220,tankY+195);
                }




           }


        if(GetAsyncKeyState(VK_SPACE))
        {
            pot=1;
            if(y>600){
             mciSendString("play expshell2.mp3",0,0,0);
             readimagefile("background.jpg",0,0,screenWidth,screenHeight);
             lives(life);
             score(scr);
             readimagefile("canontank.gif",tankX-2,tankY+1,tankX+220-2,tankY+195+1);
             flag=1;

             i=0;
            }

        }


       // cout<<fat<<" "<<DanBam<<endl;

    //    cleardevice();




        //mciSendString("play chop.mp3",0,0,0);

        scrboss=hatch+enemy;


         if(scrboss==5)
            {
                setvisualpage(page);


                mciSendString("play epicboss.mp3",0,0,0);
                readimagefile("comm.jpg",0,0,screenWidth,screenHeight);


                hatch++;

                delay(6800);

            }


        //Period Of Chopper Invaders
        if(enemy>=5)
            {
            //mciSendString("play machine.mp3",0,0,0);
            //mciSendString("play boss.mp3",0,0,0);

                printf("tankx= %d %d %d\n",tankX,bulletx,bullety);


                if((cpdhakka<sW)&&(cpdhakka>0))
                 {
                    readimagefile("bullet.gif",bulletx,bullety,bulletx+90,bullety+70);
                    bullety=bullety+16;
                    if(bullety>800)
                        {
                        bullety=145;
                        bulletx=cpdhakka+50;
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

                if((imageX-cpdhakka>=-40&&imageX-cpdhakka<=240)&&(y-cphigh<=60&&y-cphigh>=10))
                {

                    readimagefile("explode.gif",cpdhakka+60,cphigh-40,cpdhakka+160,cphigh+103);
                    mciSendString("play heliex.wav",0,0,0);
                    helipot++;
                    i=0;
                    flag=0;

     cout<<"it is" <<bullety<<endl;
                    scr=scr+50;
                    if(helipot>=3)
                        break;

                }



                 if((tankX-bulletx-10>=-170&&tankX-bulletx<=140-110)&&(bullety>=629&&bullety<=753))
                {
                    setvisualpage(page);
                    readimagefile("explode.gif",tankX+50,tankY+20,tankX+180,tankY+165);
                    mciSendString("play good.mp3",0,0,0);
                    bullety=801;
                    delay(500);
                    life++;

                    scr=scr-150;
                }


                    /*if((bullety<sH)&&(bullety>0)){
                    //mciSendString("play good.mp3",0,0,0);
                    setvisualpage(page);
                    readimagefile("explode.gif",tankX+20,tankY-15,tankX+70,tankY+25);
                    delay(500);
                    life++;
                    scr=scr-150;
                    }*/



                 score(scr);

            }





          //Period of Plane Invaders
        if(enemy<5){


        readimagefile("newplane.gif",dhakka,obhigh,dhakka+150,obhigh+75);

        readimagefile("goodplane2.gif",gddhakka,gdhigh,gddhakka+130,gdhigh+80);



        dhakka=dhakka-obspeed;

        gddhakka=gddhakka-gdspeed;


        if(dhakka<-100){
            dhakka=2500;
            potaka++;
            life++;

            if(potaka%4==1) {dhakka=sW+470; obspeed=18; obhigh=70;}
            if(potaka%4==2) {dhakka=sW+370; obspeed=16; obhigh=160;}
            if(potaka%4==3) {dhakka=sW+270; obspeed=12; obhigh=80;}
            if(potaka%4==0) {dhakka=sW+670; obspeed=19; obhigh=200;}


        }


        if(gddhakka<-100){

            gddhakka=2100;
            potaka2++;

            if(potaka2%4==1) {gddhakka=sW+670; gdspeed=18; gdhigh=50;}
            if(potaka2%4==2) {gddhakka=sW+170; gdspeed=16; gdhigh=180;}
            if(potaka2%4==3) {gddhakka=sW+370; gdspeed=12; gdhigh=90;}
            if(potaka2%4==0) {gddhakka=sW+470; gdspeed=19; gdhigh=170;}
        }

        setcolor(WHITE);

        if((imageX+30-dhakka>=-40&&imageX+30-dhakka<=80)&&(y-obhigh<=60&&y-obhigh>=-05))
            {
            //readimagefile("newplanecrush.gif",dhakka,obhigh,dhakka+150,obhigh+75);




            readimagefile("explode.gif",dhakka,obhigh-40,dhakka+150,obhigh+100);
            mciSendString("play COLL.mp3",0,0,0);
            scr=scr+100;

            delay(550);
            potaka++;
            enemy++;
            i=0;
            flag=0;

            if(potaka%4==1) {dhakka=sW+470; obspeed=18; obhigh=70;}
            if(potaka%4==2) {dhakka=sW+370; obspeed=16; obhigh=160;}
            if(potaka%4==3) {dhakka=sW+270; obspeed=12; obhigh=80;}
            if(potaka%4==0) {dhakka=sW+670; obspeed=19; obhigh=200;}

            }




        if((imageX-gddhakka>=-60&&imageX-gddhakka<=80)&&(y-gdhigh<=60&&y-gdhigh>=-10))
            {
            //readimagefile("newplanecrush.gif",dhakka,obhigh,dhakka+150,obhigh+75);




            readimagefile("explode.gif",gddhakka,gdhigh-40,gddhakka+150,gdhigh+100);
            mciSendString("play good.mp3",0,0,0);
            scr=scr-150;
            life++;
            potaka2++;
            i=0;
            flag=0;

            if(potaka2%4==1) {gddhakka=sW+670; gdspeed=18; gdhigh=50;}
            if(potaka2%4==2) {gddhakka=sW+170; gdspeed=16; gdhigh=180;}
            if(potaka2%4==3) {gddhakka=sW+370; gdspeed=12; gdhigh=90;}
            if(potaka2%4==0) {gddhakka=sW+470; gdspeed=19; gdhigh=170;}

            }
    }


        if(life==3)
                break;


        page=1-page;
        alo++;

    }

    cleardevice();
    setvisualpage(page);
    if(life!=3){
        readimagefile("lvl2.jpg",0,0,screenWidth,screenHeight);
        delay(2000);
        mciSendString("play level.wav",0,0,0);
        delay(4000);
    }

    int scboss=0, hat=0, enem=0;
    cpdhakka=screenWidth+350, cpflag=2, tankX=41,tankY=605, imageX=tankX+56, helipot=0, bullety=150, check=0, check2=0, bulletx=cpdhakka+50, DanBam=200;

     while(1)

  {
            setvisualpage(1-page);
            setactivepage(page);
         //   cleardevice();

            mciSendString("play backmusic.wav",0,0,0);
            if(life==3)
                break;


            int din=alo%100;


           // scrboss=hatch+potaka;



            readimagefile("n8background.jpg",0,0,screenWidth,screenHeight);
            lives(life);
            score(scr);



            //readimagefile("sun2.gif",50,25,125,115);
            readimagefile("newtank2.gif",tankX,tankY,tankX+260,tankY+194);

            y=pow(i-height,2)/fat+shuru;

            if(flag==1)
            {
                i+=50; //speed
                 imageX=i+DanBam; //imageX holo shell er initial X
                 readimagefile("fire 2.gif",imageX,y,imageX+19,y+19);
            }


            if(life==3)
                break;

            if(y>650)
            {
                  readimagefile("n8background.jpg",0,0,screenWidth,screenHeight);
                  lives(life);
                  score(scr);
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
                   lives(life);
                   score(scr);
                   readimagefile("tankmove.gif",tankX,tankY,tankX+260,tankY+194);
               }

                if(GetAsyncKeyState(VK_LEFT))
                {
                 delay(500);
                   DanBam-=40;
                   tankX-=40;
                   readimagefile("n8background.jpg",0,0,screenWidth,screenHeight);
                   lives(life);
                   score(scr);
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
             lives(life);
             score(scr);
             readimagefile("newtank2.gif",tankX,tankY,tankX+260,tankY+194);
             flag=1;

             i=0;
            }

        }


       // cout<<fat<<" "<<DanBam<<endl;

    //    cleardevice();




        //mciSendString("play chop.mp3",0,0,0);

            scboss=enem+hat;
         if(scboss==4)
            {
                setvisualpage(page);

                mciSendString("play epicboss.mp3",0,0,0);
                readimagefile("comm1.jpg",0,0,screenWidth,screenHeight);



                hat++;

                delay(5000);

            }


        //Period Of Chopper Invaders
        if(enem>=4){
            //mciSendString("play machine.mp3",0,0,0);
            //mciSendString("play boss.mp3",0,0,0);
            if((cpdhakka<sW)&&(cpdhakka>0))
            {
                readimagefile("bullet.gif",bulletx,bullety,bulletx+90,bullety+70);
                    bullety=bullety+16;
                    if(bullety>800)
                        {
                        bullety=145;
                        bulletx=cpdhakka+50;
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

            if((imageX-cpdhakka>=-40&&imageX-cpdhakka<=240)&&(y-cphigh<=60&&y-cphigh>=10))
            {

                readimagefile("explode.gif",cpdhakka+60,cphigh-40,cpdhakka+160,cphigh+103);
                mciSendString("play heliex.wav",0,0,0);
                helipot++;
                i=0;
                flag=0;
                scr=scr+50;

                if(helipot>=3)
                    break;

            }

            if((tankX+90-bulletx>=-170&&tankX+40-bulletx<=140)&&(bullety>=629&&bullety<=753))
                {
                    setvisualpage(page);
                    readimagefile("explode.gif",tankX+50,tankY+20,tankX+180,tankY+165);
                    mciSendString("play good.mp3",0,0,0);
                    bullety=801;
                    delay(500);
                    life++;

                    scr=scr-150;
                }

        }

          //Period of Plane Invaders
        if(enem<4){


        /*readimagefile("lvlplane.gif",lvldhakka,lvlhigh,lvldhakka+150,lvlhigh+72);

        readimagefile("lvlgdplane.gif",lvlgddhakka,lvlgdhigh,lvlgddhakka+150,lvlgdhigh+72);*/

        readimagefile("newplane.gif",lvldhakka,lvlhigh,lvldhakka+150,lvlhigh+75);

        readimagefile("goodplane2.gif",lvlgddhakka,lvlgdhigh,lvlgddhakka+140,lvlgdhigh+82);



        lvldhakka=lvldhakka-lvlspeed;

        lvlgddhakka=lvlgddhakka-lvlgdspeed;


        if(lvldhakka<-100){
            lvldhakka=2500;
            check++;
            life++;
            scr=scr-150;

            if(check%4==1) {lvldhakka=sW+550; lvlspeed=18; lvlhigh=70;}
            if(check%4==2) {lvldhakka=sW+350; lvlspeed=16; lvlhigh=110;}
            if(check%4==3) {lvldhakka=sW+270; lvlspeed=12; lvlhigh=80;}
            if(check%4==0) {lvldhakka=sW+430; lvlspeed=17; lvlhigh=200;}


        }


        if(lvlgddhakka<-100){

            lvlgddhakka=2100;
            check2++;

            if(check2%4==1) {lvlgddhakka=sW+670; lvlgdspeed=12; lvlgdhigh=50;}
            if(check%4==2)  {lvlgddhakka=sW+170; lvlgdspeed=19; lvlgdhigh=190;}
            if(check2%4==3) {lvlgddhakka=sW+370; lvlgdspeed=14; lvlgdhigh=90;}
            if(check2%4==0) {lvlgddhakka=sW+120; lvlgdspeed=17; lvlgdhigh=170;}
        }


        if((imageX-lvldhakka>=-40&&imageX-lvldhakka<=80)&&(y-lvlhigh<=60&&y-lvlhigh>=-05))


            {
            //readimagefile("newplanecrush.gif",dhakka,obhigh,dhakka+150,obhigh+75);




            readimagefile("explode.gif",lvldhakka,lvlhigh-40,lvldhakka+150,lvlhigh+100);
            mciSendString("play COLL.mp3",0,0,0);
            scr=scr+100;

            delay(550);
            check++;
            i=0;
            flag=0;
            enem++;

            if(check%4==1) {lvldhakka=sW+550; lvlspeed=18; lvlhigh=70;}
            if(check%4==2) {lvldhakka=sW+350; lvlspeed=16; lvlhigh=160;}
            if(check%4==3) {lvldhakka=sW+270; lvlspeed=12; lvlhigh=80;}
            if(check%4==0) {lvldhakka=sW+430; lvlspeed=17; lvlhigh=200;}

            }




        if((imageX-lvlgddhakka>=-60&&imageX-lvlgddhakka<=80)&&(y-lvlgdhigh<=60&&y-lvlgdhigh>=-10))
            {
            //readimagefile("newplanecrush.gif",dhakka,obhigh,dhakka+150,obhigh+75);




            readimagefile("explode.gif",lvlgddhakka,lvlgdhigh-40,lvlgddhakka+150,lvlgdhigh+100);
            mciSendString("play good.mp3",0,0,0);

            check2++;
            i=0;
            flag=0;
            scr=scr-150;
            life++;

            if(check2%4==1) {lvlgddhakka=sW+670; lvlgdspeed=12; lvlgdhigh=50;}
            if(check%4==2) {lvlgddhakka=sW+170; lvlgdspeed=19; lvlgdhigh=180;}
            if(check2%4==3) {lvlgddhakka=sW+370; lvlgdspeed=14; lvlgdhigh=90;}
            if(check2%4==0) {lvlgddhakka=sW+120; lvlgdspeed=17; lvlgdhigh=170;}

            }
    }


        page=1-page;
        alo++;

    }
    setvisualpage(page);
    if(life==3){
        readimagefile("gameover.jpg",0,0,screenWidth,screenHeight);
        mciSendString("play over.mp3",0,0,0);
        finalscore(scr);

        delay(8000);
    }
    setvisualpage(page);
    if(life!=3){
        mciSendString("play win.mp3",0,0,0);
        readimagefile("win.jpg",0,0,screenWidth,screenHeight);
        finalscore(scr);
        delay(8000);
    }
    getch();
    scr=0;
    goto starts;

    return 0;
}

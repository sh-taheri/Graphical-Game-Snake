
#include "stdafx.h"
#include "HW5_test.h"
#include "CNibble.h"

#define VK_LEFT 0x25
#define VK_UP 0x26
#define VK_RIGHT 0x27
#define VK_DOWN 0x28
#define VK_A    0x41
#define VK_D    0x44
#define VK_S    0x53
#define VK_W    0x57
 
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif
/////////////////////////////////////////////////////////////////////// Change Direction /////////////////////////////////////////////////////////////////////////////////////////
void CNibble :: ChangeDir(UINT key,int PN){
	if(PN==2){
		switch(key){
		case VK_LEFT: {MoveDir='L';break;}
		case VK_UP : {MoveDir='U';break;}
		case VK_RIGHT:{MoveDir='R';break;}
		case VK_DOWN :{MoveDir='D';break;}
		}
	}
	if(PN==1)
		switch(key){
		case VK_A: {MoveDir='l';break;}
		case VK_W: {MoveDir='u';break;}
		case VK_D:{MoveDir='r';break;}
		case VK_S :{MoveDir='d';break;}
		}
}
///////////////////////////////////////////////////////////////////////// Move Right ////////////////////////////////////////////////////////////////////////////////////////////////////
CPoint CNibble :: MoveRight(){
CPoint Nibble_new_head=CPoint(points[point_num-1].x+1,points[point_num-1].y);
	    add_point(Nibble_new_head);
	    CPoint S=delete_point();
		return S;
}

/////////////////////////////////////////////////////////////////////////Move Left //////////////////////////////////////////////////////////////////////////////////////////////////////
CPoint CNibble :: MoveLeft(){
CPoint Nibble_new_head=CPoint(points[point_num-1].x-1,points[point_num-1].y);
	    add_point(Nibble_new_head);
	   CPoint S=delete_point();
		return S;
}
/////////////////////////////////////////////////////////////////////////Move Up/////////////////////////////////////////////////////////////////////////////////////////////////////////////
CPoint CNibble :: MoveUp(){
CPoint Nibble_new_head=CPoint(points[point_num-1].x,points[point_num-1].y-1);
	    add_point(Nibble_new_head);
	    CPoint S=delete_point();
		return S;
}
////////////////////////////////////////////////////////////////////////Move Down/////////////////////////////////////////////////////////////////////////////////////////////////////////
CPoint CNibble :: MoveDown(){
CPoint Nibble_new_head=CPoint(points[point_num-1].x,points[point_num-1].y+1);
	    add_point(Nibble_new_head);
	    CPoint S=delete_point();
		return S;
}
////////////////////////////////////////////////////////////// Move Direction For Nibbles ////////////////////////////////////////////////////////////////////////////////////
CPoint CNibble :: Move(int PN){
	CPoint last_point;
	if (PN==2){
	switch(MoveDir){
     case 'L' : { last_point=MoveLeft();break;}
	 case 'R' : { last_point=MoveRight();break;}
	 case 'U' : { last_point=MoveUp();break;}
	 case 'D' : { last_point=MoveDown();break;}
	               }
	         }
	if(PN==1)
	{
	 switch(MoveDir){
     case 'l' : { last_point=MoveLeft();break;}
	 case 'r' : { last_point=MoveRight();break;}
	 case 'u' : { last_point=MoveUp();break;}
	 case 'd' : { last_point=MoveDown();break;}
	               }
	}
	return last_point;
}
///////////////////////////////////////////////////////////// Assigning Head Point Of the Nibble ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
CPoint CNibble :: HeadPoint(){
return points[point_num-1];
}
///////////////////////////////////// Defining Read function in order to get the coordinate of nibbles from a file /////////////////////////////////////////////////////////////////////////////////
void CNibble::read(const char *file_name){
	point_num=0;
	int i=0;
	FILE *fp;
 fp = fopen ( file_name, "r" ) ; 
  if ( fp == NULL ) 
     {puts ( "Cannot open file" ) ;exit(1) ;}
 while(fscanf( fp,"%d%d\n", & points[i].x,&points[i].y)!=EOF) 
  { point_num++;
	i++;
}
  fclose ( fp ) ; 
}

///////////////////////////////////// Defining Write function in order to write the coordinate of nibbles to a file /////////////////////////////////////////////////////////////////////////////
void CNibble :: write(const char *file_name,CNibble nb){
  FILE  *fp ;  
  fp = fopen ( file_name, "w" ) ; 
  if ( fp == NULL ) 
     {puts ( "Cannot open file" ) ;exit(1) ;} 
  for (int i=0;i<point_num;i++)
   fprintf ( fp,"%d %d",points[i].x,points[i].y);
  fclose ( fp ) ; 
}
///////////////////////////////////// Defining add & delete function in order to make it move ///////////////////////////////////////////////////////////////////////////
void CNibble ::add_point( CPoint p){
	points[point_num]=p;
	point_num++;

}
CPoint CNibble ::delete_point(){
	CPoint p1=points[0];
   for (int i=0;i<point_num-1;i++)
	   points[i]=points[i+1];
   point_num--;
   return p1;

}
///////////////////////////////////// Defining check_point function to check out if the point is on the nibble ///////////////////////////////////////////////////////////
int CNibble ::check_point(CPoint p){
	int flag=0;
	for ( int i=0;i<point_num;i++)
	{ if(points[i]==p) {flag=1; break;}}
	return flag;
}
////////////////////////////////////////////// Defining Draw function to draw the nibble's points ///////////////////////////////////////////////////////////////////////////
 void CNibble :: draw(int h,CPoint p,CDC *pDC,COLORREF color,int row){
		CBrush aBrush(color);pDC->SelectObject(aBrush); // 1 : Red color
 for (int i=0;i<point_num;i++)
	 {CRect Recto((points[i].x-1) *(h/row) + p.x, (points[i].y-1) * (h/row) + p.y,(points[i].x )*(h/row) + p.x,(points[i].y)*(h/row) + p.y);
      Nibble_cells[i]=Recto;pDC->Rectangle(&Recto);}
 }
 ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
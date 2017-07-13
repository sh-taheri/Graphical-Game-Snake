
#if !defined(AFX_NOTESVIEW_H__155489BF_0B24_4D59_B185_74715A0762F7__INCLUDED_)
#define AFX_NOTESVIEW_H__155489BF_0B24_4D59_B185_74715A0762F7__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class CNibble {
 public:
 int point_num;
 CPoint *points;
 CRect Nibble_cells[100];
 void ChangeDir(UINT,int PN);
 char MoveDir;
 CPoint MoveRight();
 CPoint MoveLeft();
 CPoint MoveUp();
 CPoint MoveDown();
 CPoint HeadPoint();
 CPoint Move(int PN);
 CNibble() { points= new CPoint[100];} // constructor
 CNibble( int num) { points= new CPoint[num]; point_num=num;} // overloading constructor
 CNibble(const CNibble &A) { for(int i=0;i<A.point_num;i++) {points[i]=A.points[i];/*int color=A.color;*/}; } // copy constructor
 ~CNibble() { delete[] points;}
 void read(const char *file_name);
 void write(const char *file_name,CNibble nb);
 void add_point(CPoint p);
 CPoint delete_point();
 int check_point(CPoint p); 
 void draw(int h,CPoint p,CDC *pDC,COLORREF color,int row);
};



#endif // !defined(AFX_NOTESVIEW_H__155489BF_0B24_4D59_B185_74715A0762F7__INCLUDED_)
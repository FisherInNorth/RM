#ifndef REFEREE_UI_H
#define REFEREE_UI_H
#include "main.h"
#define MAX_SIZE          128    //�ϴ��������ĳ���
#define frameheader_len  5       //֡ͷ����
#define cmd_len          2       //�����볤��
#define crc_len          2       //CRC16У��
/****************************�췽������ID********************/
#define UI_Data_RobotID_RHero 1         
#define UI_Data_RobotID_REngineer 2
#define UI_Data_RobotID_RStandard1 3
#define UI_Data_RobotID_RStandard2 4
#define UI_Data_RobotID_RStandard3 5
#define UI_Data_RobotID_RAerial 6
#define UI_Data_RobotID_RSentry 7
#define UI_Data_RobotID_RRadar 9
/****************************����������ID********************/
#define UI_Data_RobotID_BHero 101
#define UI_Data_RobotID_BEngineer 102
#define UI_Data_RobotID_BStandard1 103
#define UI_Data_RobotID_BStandard2 104
#define UI_Data_RobotID_BStandard3 105
#define UI_Data_RobotID_BAerial 106
#define UI_Data_RobotID_BSentry 107
#define UI_Data_RobotID_BRadar 109
/**************************�췽������ID************************/
#define UI_Data_CilentID_RHero 0x0101
#define UI_Data_CilentID_REngineer 0x0102
#define UI_Data_CilentID_RStandard1 0x0103
#define UI_Data_CilentID_RStandard2 0x0104
#define UI_Data_CilentID_RStandard3 0x0105
#define UI_Data_CilentID_RAerial 0x0106
/***************************����������ID***********************/
#define UI_Data_CilentID_BHero 0x0165
#define UI_Data_CilentID_BEngineer 0x0166
#define UI_Data_CilentID_BStandard1 0x0167
#define UI_Data_CilentID_BStandard2 0x0168
#define UI_Data_CilentID_BStandard3 0x0169
#define UI_Data_CilentID_BAerial 0x016A
/***************************ɾ������***************************/
#define UI_Data_Del_NoOperate 0
#define UI_Data_Del_Layer 1
#define UI_Data_Del_ALL 2
/***************************ͼ�����ò���__ͼ�β���********************/
#define UI_Graph_ADD 1
#define UI_Graph_Change 2
#define UI_Graph_Del 3
/***************************ͼ�����ò���__ͼ������********************/
#define UI_Graph_Line 0         //ֱ��
#define UI_Graph_Rectangle 1    //����
#define UI_Graph_Circle 2       //��Բ
#define UI_Graph_Ellipse 3      //��Բ
#define UI_Graph_Arc 4          //Բ��
#define UI_Graph_Float 5        //������
#define UI_Graph_Int 6          //����
#define UI_Graph_Char 7         //�ַ���
/***************************ͼ�����ò���__ͼ����ɫ********************/
#define UI_Color_Main 0         //������ɫ
#define UI_Color_Yellow 1
#define UI_Color_Green 2
#define UI_Color_Orange 3
#define UI_Color_Purplish_red 4 //�Ϻ�ɫ
#define UI_Color_Pink 5
#define UI_Color_Cyan 6         //��ɫ
#define UI_Color_Black 7
#define UI_Color_White 8


#define SCREEN_WIDTH 1080
#define SCREEN_LENGTH 1920

#define ON 		1
#define OFF		0

//void UI_draw_Line(char imagename[3],uint32_t Graph_Operate,uint32_t Graph_Layer,uint32_t Graph_Color,uint32_t Graph_Width,uint32_t Start_x,uint32_t Start_y,uint32_t End_x,uint32_t End_y);
//void UI_draw_Rectangle(char imagename[3],uint32_t Graph_Operate,uint32_t Graph_Layer,uint32_t Graph_Color,uint32_t Graph_Width,uint32_t Start_x,uint32_t Start_y,uint32_t End_x,uint32_t End_y);
//void UI_draw_Circle(char imagename[3],uint32_t Graph_Operate,uint32_t Graph_Layer,uint32_t Graph_Color,uint32_t Graph_Width,uint32_t Start_x,uint32_t Start_y,uint32_t Graph_Radius);
//void UI_draw_Arc(char imagename[3],uint32_t Graph_Operate,uint32_t Graph_Layer,uint32_t Graph_Color,uint32_t Graph_StartAngle,uint32_t Graph_EndAngle,uint32_t Graph_Width,uint32_t Start_x,uint32_t Start_y,uint32_t x_Length,uint32_t y_Length);
//void UI_draw_Float(char imagename[3],uint32_t Graph_Operate,uint32_t Graph_Layer,uint32_t Graph_Color,uint32_t Graph_Size,uint32_t Graph_Digit,uint32_t Graph_Width,uint32_t Start_x,uint32_t Start_y,float Graph_Float);
//void UI_draw_Int(char imagename[3],uint32_t Graph_Operate,uint32_t Graph_Layer,uint32_t Graph_Color,uint32_t Graph_Size,uint32_t Graph_Width,uint32_t Start_x,uint32_t Start_y,int32_t Graph_Int);
//void UI_character_draw_data(char imagename[3],uint32_t Graph_Operate,uint32_t Graph_Layer,uint32_t Graph_Color,uint32_t Graph_Size,uint32_t Graph_Digit,uint32_t Graph_Width,uint32_t Start_x,uint32_t Start_y,char *Char_Data);

void UI_Init(void);
void UI_Display(void);
#endif
#include "BSP_Mineral.h"
#include "pid.h"
#include "BSP_Motor.h"
#include "BSP_Can.h"

MOTOR_MOVE_t mineral_longitudinal_move;
MOTOR_MOVE_t mineral_widthwise_move;

MOTOR_t mineral_F_motor;//ǰ��ĵ��
MOTOR_t mineral_B_motor;//����ĵ��
MOTOR_t mineral_R_motor;//�ұߵĵ��
MOTOR_t mineral_L_motor;//��ߵĵ��

uint8_t current_msg[8];
int Mineral_Longitudinal_Speed=60;
int Mineral_Widthwise_Speed=60;
float Mineral_Kp=8.0;
float Mineral_Ki=1.2;				
float Mineral_Kd=0.5;

/**
	* @function����:Mineral_Init
	* @brief����:��е�۳�ʼ��
	* @param����:��
	* @retval����ֵ:��
  */
void Mineral_Init(void)
{
	mineral_longitudinal_move=stop;           mineral_widthwise_move=stop;
	mineral_F_motor.round_cnt=0.0f;			      mineral_B_motor.round_cnt=0.0f;
	mineral_F_motor.target_current=0;		      mineral_B_motor.target_current=0;
	mineral_F_motor.actual_current=0;		      mineral_B_motor.actual_current=0;
	mineral_F_motor.vpid.target_speed=0;			mineral_B_motor.vpid.target_speed=0;
	mineral_F_motor.vpid.actual_speed=0.0f;	  mineral_B_motor.vpid.actual_speed=0.0f;
	mineral_F_motor.vpid.err=0;               mineral_B_motor.vpid.err=0;
	mineral_F_motor.vpid.last_err=0;          mineral_B_motor.vpid.last_err=0;
	mineral_F_motor.vpid.err_integration=0;   mineral_B_motor.vpid.err_integration=0; 
	mineral_F_motor.vpid.P_OUT=0;             mineral_B_motor.vpid.P_OUT=0;
	mineral_F_motor.vpid.I_OUT=0;             mineral_B_motor.vpid.I_OUT=0;
	mineral_F_motor.vpid.D_OUT=0;             mineral_B_motor.vpid.D_OUT=0;
	mineral_F_motor.vpid.PID_OUT=0;           mineral_B_motor.vpid.PID_OUT=0;
	mineral_F_motor.vPID_max=3000;						mineral_B_motor.vPID_max=3000;

	mineral_R_motor.round_cnt=0.0f;			      mineral_L_motor.round_cnt=0.0f;
	mineral_R_motor.target_current=0;		      mineral_L_motor.target_current=0;
	mineral_R_motor.actual_current=0;		      mineral_L_motor.actual_current=0;
	mineral_R_motor.vpid.target_speed=0;			mineral_L_motor.vpid.target_speed=0;
	mineral_R_motor.vpid.actual_speed=0.0f;	  mineral_L_motor.vpid.actual_speed=0.0f;
	mineral_R_motor.vpid.err=0;               mineral_L_motor.vpid.err=0;
	mineral_R_motor.vpid.last_err=0;          mineral_L_motor.vpid.last_err=0;
	mineral_R_motor.vpid.err_integration=0;   mineral_L_motor.vpid.err_integration=0; 
	mineral_R_motor.vpid.P_OUT=0;             mineral_L_motor.vpid.P_OUT=0;
	mineral_R_motor.vpid.I_OUT=0;             mineral_L_motor.vpid.I_OUT=0;
	mineral_R_motor.vpid.D_OUT=0;             mineral_L_motor.vpid.D_OUT=0;
	mineral_R_motor.vpid.PID_OUT=0;           mineral_L_motor.vpid.PID_OUT=0;
	mineral_R_motor.vPID_max=3000;						mineral_L_motor.vPID_max=3000;

}

/**
	* @function����:Set_Mineral_F/B_Speed
	* @brief����:����ǰ���������ת��
	* @param����:Ŀ���ٶ�
	* @retval����ֵ:��
  */
void Set_Mineral_F_Speed(int target_speed)
{
	mineral_F_motor.vpid.target_speed = target_speed*36; 
}

void Set_Mineral_B_Speed(int target_speed)
{
	mineral_B_motor.vpid.target_speed = target_speed*36;
}

/**
	* @function����:Set_Mineral_R/L_Speed
	* @brief����:�ֱ���������������
	* @param����:Ŀ���ٶ�
	* @retval����ֵ:��
  */

void Set_Mineral_R_Speed(int target_speed)
{
	mineral_R_motor.vpid.target_speed = target_speed*36;
}
void Set_Mineral_L_Speed(int target_speed)
{
	mineral_L_motor.vpid.target_speed = target_speed*36;
}

/**
	* @function����:Vpid_Mineral_Realize
	* @brief����:��е�۵���ٶ�pidʵ��
	* @param����:��е�۵���ٶ�pidϵ��
	* @retval����ֵ:��
  */
void Vpid_Mineral_Longitudinal_Realize(float kp,float ki,float kd)
{
	Vpid_Realize(&mineral_F_motor, kp, ki, kd);
	Vpid_Realize(&mineral_B_motor, kp, ki, kd);
}
void Vpid_Mineral_Widthwise_Realize(float kp,float ki,float kd)
{
	Vpid_Realize(&mineral_R_motor, kp, ki, kd);
	Vpid_Realize(&mineral_L_motor, kp, ki, kd);
}



/**
	* @brief  ����Mineral������ֵ������can1��
	* @param void
	* @retval void
	* @attention
	*/
void Set_Mineral_Current()
{

	//���Ŀ�����Ϊ�ٶ�pid���
	mineral_F_motor.target_current =mineral_F_motor.vpid.PID_OUT;// Mineral_Current_F;//
	mineral_B_motor.target_current =mineral_B_motor.vpid.PID_OUT;//Mineral_Current_B;// 
	//can����ͨ��Э�飬���յ��˵����
	current_msg[0] = mineral_F_motor.target_current >> 8;			//1�ŵ��������8λ
	current_msg[1] = mineral_F_motor.target_current & 0xff;		//1�ŵ��������8λ
	current_msg[2] = mineral_B_motor.target_current >> 8;			//1�ŵ��������8λ
	current_msg[3] = mineral_B_motor.target_current & 0xff;		//1�ŵ��������8λ
	
	mineral_R_motor.target_current =mineral_R_motor.vpid.PID_OUT;//Mineral_Current_R;
	mineral_L_motor.target_current =mineral_L_motor.vpid.PID_OUT;//Mineral_Current_L
	//can����ͨ��Э�飬���յ��˵����
	current_msg[4] = mineral_R_motor.target_current >> 8;			//1�ŵ��������8λ
	current_msg[5] = mineral_R_motor.target_current & 0xff;		//1�ŵ��������8λ
	current_msg[6] = mineral_L_motor.target_current >> 8;			//1�ŵ��������8λ
	current_msg[7] = mineral_L_motor.target_current & 0xff;		//1�ŵ��������8λ
	
	//can��������֡
	CAN1_Send_Mineral_Msg(current_msg);
}


/**
	* @brief Mineral����ִ�к���
	* @param void
	* @retval void
	* @attention
	*/

void Mineral_Task_Longitudinal(MOTOR_MOVE_t mineral_longitudinal_move)
{
	switch(mineral_longitudinal_move)
	{
		case forward:
		{
			Set_Mineral_F_Speed(Mineral_Longitudinal_Speed);
			Set_Mineral_B_Speed(Mineral_Longitudinal_Speed);
		}
		break;
		case back:
		{
			Set_Mineral_F_Speed(-Mineral_Longitudinal_Speed);
			Set_Mineral_B_Speed(-Mineral_Longitudinal_Speed);
		}
		break;
		case down:
		{
			Set_Mineral_F_Speed(-Mineral_Widthwise_Speed);
			Set_Mineral_B_Speed(Mineral_Widthwise_Speed);
		}
	   break;
		case up:
		{
			Set_Mineral_F_Speed(Mineral_Widthwise_Speed);
			Set_Mineral_B_Speed(-Mineral_Widthwise_Speed);
		}
		break;
		case stop:
		{
			Set_Mineral_F_Speed(0);
			Set_Mineral_B_Speed(0);
		}
		break;
		default:
			break;
	}

	Vpid_Mineral_Longitudinal_Realize(Mineral_Kp, Mineral_Ki, Mineral_Kd);
	Set_Mineral_Current();
}

void Mineral_Task_Widthwise(MOTOR_MOVE_t mineral_widthwise_move)
{
	switch(mineral_widthwise_move)
	{
		case right:
		{
			Set_Mineral_R_Speed(Mineral_Widthwise_Speed);
			Set_Mineral_L_Speed(Mineral_Widthwise_Speed);
		}
		break;
		case left:
		{
			Set_Mineral_R_Speed(-Mineral_Widthwise_Speed);
			Set_Mineral_L_Speed(-Mineral_Widthwise_Speed);		
		}
		break;
		case down:
		{
			Set_Mineral_R_Speed(Mineral_Widthwise_Speed);
			Set_Mineral_L_Speed(-Mineral_Widthwise_Speed);
		}
		break;
		case up:
		{
			Set_Mineral_R_Speed(-Mineral_Widthwise_Speed);
			Set_Mineral_L_Speed(Mineral_Widthwise_Speed);
		}
		break;
		case stop:
		{
			Set_Mineral_R_Speed(0);
			Set_Mineral_L_Speed(0);
		}
		break;
		default:
			break;
	}

	Vpid_Mineral_Widthwise_Realize(Mineral_Kp, Mineral_Ki, Mineral_Kd);
	Set_Mineral_Current();
}

	
#include<P89V51RD2.H>		
#include<ROBOT_UART.c>
#define SYSCLK 11059200				

sbit Jaw_Forward = P2^0;
sbit Jaw_Reverse = P2^1;

sbit Neck_Forward = P2^2;
sbit Neck_Reverse = P2^3;
sbit L_Motor_Data1 = P2^4;
sbit L_Motor_Data2 = P2^5;
sbit R_Motor_Data1 = P2^6;
sbit R_Motor_Data2 = P2^7;
sbit Front_IR = P1^3;
sbit TOGGLE_SW = P1^0;
void Device_Init( void );
void Robot_OFF( );
void Forward_L_R( void );
void Rotate_L( void );
void Rotate_R( void );
void Reverse_L_R( void );
void Rotate_Pick_Arm_L( void );
void Rotate_Pick_Arm_R( void );
void Rotate_Pick_Arm_F( void );
void Rotate_Pick_Arm_B( void );
void MSDelay( unsigned int Milli_Sec );
void main( void )
{
 Device_Init( );
	MSDelay(100);
	UART_ST( "UART TESTED" );
	Forward_L_R( );
	Rotate_L( );
	Rotate_R( );
	Reverse_L_R( );
	Rotate_Pick_Arm_L( );
	Rotate_Pick_Arm_R( );
	Rotate_Pick_Arm_F( );
	Rotate_Pick_Arm_B( );
	while(1)
	{
		if(TOGGLE_SW==1)
		{
			Rx_count = 0;									
			Rx_ST_Flag = 0;									
			while( Rx_ST_Flag == 0 )
			{
				if(TOGGLE_SW==0)
					break;
			}
			if( Rx_ST_Flag == 1 )
			{
				Rx_ST_Flag = 0;									
				switch( Rx_data_arr[0] )
				{
					case '1':
					{
						Forward_L_R( );
						break;
					}
					case '2':
					{
						Rotate_L( );
						break;
					}
					case '3':
					{
						Rotate_R( );
						break;
					}
					case '4':
					{
						Reverse_L_R( );
						break;
					}
					case '5':
					{
						Rotate_Pick_Arm_L( );
						break;
					}
					case '6':
					{
						Rotate_Pick_Arm_R( );
						break;
					}
					case '7':
					{
						Rotate_Pick_Arm_F( );
						break;
					}
					case '8':
					{
						Rotate_Pick_Arm_B( );
						break;
					}
				}
			}
		}
	
	else if(TOGGLE_SW==0)
			{

				Rotate_Pick_Arm_L( );
				Rotate_Pick_Arm_F( );
				Rotate_Pick_Arm_R( );
				Rotate_L( );
				Forward_L_R( );
				Rotate_R( );
				Forward_L_R( );
				Rotate_Pick_Arm_L( );
				Rotate_Pick_Arm_B( );
				
		        Rotate_Pick_Arm_R( );
				Reverse_L_R( );
				Rotate_R( );
				Forward_L_R( );
				Rotate_L( );
			 Rotate_Pick_Arm_L( );
				Rotate_Pick_Arm_F( );
				Rotate_Pick_Arm_R( );
				Forward_L_R( );
				Rotate_Pick_Arm_L( );
				Rotate_Pick_Arm_B( );
		    Rotate_Pick_Arm_R( );
				Reverse_L_R( );



			   Rotate_Pick_Arm_L( );
				Rotate_Pick_Arm_F( );
				Rotate_Pick_Arm_R( );
				Rotate_R( );
				Forward_L_R( );
				Rotate_L( );
				Forward_L_R( );
				Rotate_Pick_Arm_L( );
				Rotate_Pick_Arm_B( );

				Rotate_Pick_Arm_R( );
				Reverse_L_R( );
				Rotate_L( );
				Forward_L_R( );
				Rotate_R( );

			}
      }
	while(1)										
	{				   
		;
	}
}


void Device_Init( void )
{
	xdata unsigned char UC_count = 0xFD;	

	EA = 0;
	UART0M1_Tx_Init( );									
	Timer1M2_Init( UC_count );				
	EA = 1;									
	TR1 = 1;								

	L_Motor_Data1 = 0;
	L_Motor_Data2 = 0;
	R_Motor_Data1 = 0;
	R_Motor_Data2 = 0;

	Jaw_Forward = 0;
	Jaw_Reverse = 0;
	Neck_Forward = 0;
	Neck_Reverse = 0;
}


void Robot_OFF( )
{

	L_Motor_Data1 = 0;
	L_Motor_Data2 = 0;
	R_Motor_Data1 = 0;
	R_Motor_Data2 = 0;

}


void Forward_L_R( void )
{
	L_Motor_Data1 = 1;
	L_Motor_Data2 = 0;
	R_Motor_Data1 = 1;
	R_Motor_Data2 = 0;
	MSDelay(1000);

	L_Motor_Data1 = 0;
	L_Motor_Data2 = 0;
	R_Motor_Data1 = 0;
	R_Motor_Data2 = 0;
	MSDelay(100);

}


void Rotate_L( void )
{
	L_Motor_Data1 = 0;
	L_Motor_Data2 = 1;
	R_Motor_Data1 = 1;
	R_Motor_Data2 = 0;
	MSDelay(700);

	L_Motor_Data1 = 0;
	L_Motor_Data2 = 0;
	R_Motor_Data1 = 0;
	R_Motor_Data2 = 0;
	MSDelay(100);

}

void Rotate_R( void )
{
	L_Motor_Data1 = 1;
	L_Motor_Data2 = 0;
	R_Motor_Data1 = 0;
	R_Motor_Data2 = 1;
	MSDelay(700);

	L_Motor_Data1 = 0;
	L_Motor_Data2 = 0;
	R_Motor_Data1 = 0;
	R_Motor_Data2 = 0;
	MSDelay(100);	
}

 void Reverse_L_R( void )
{
	L_Motor_Data1 = 0;
	L_Motor_Data2 = 1;
	R_Motor_Data1 = 0;
	R_Motor_Data2 = 1;
	MSDelay(1000);

	L_Motor_Data1 = 0;
	L_Motor_Data2 = 0;
	R_Motor_Data1 = 0;
	R_Motor_Data2 = 0;
	MSDelay(100);

}
void Rotate_Pick_Arm_L( void )
{
	Jaw_Forward = 0;
	Jaw_Reverse = 1;
	MSDelay(700);
	Jaw_Forward = 0;
	Jaw_Reverse = 0;
	MSDelay(100);
}
void Rotate_Pick_Arm_R( void )
{
	Jaw_Forward = 1;
	Jaw_Reverse = 0;
	MSDelay(700);
	Jaw_Forward = 0;
	Jaw_Reverse = 0;
	MSDelay(100);
}
void Rotate_Pick_Arm_F( void )
{
	Neck_Forward = 0;
	Neck_Reverse = 1;
	MSDelay(700);
	Neck_Forward = 0;
	Neck_Reverse = 0;
	MSDelay(100);
}
void Rotate_Pick_Arm_B( void )
{
	Neck_Forward = 1;
	Neck_Reverse = 0;
	MSDelay(700);
	Neck_Forward = 0;
	Neck_Reverse = 0;
	MSDelay(100);
}

void MSDelay( unsigned int Milli_Sec )
{
    data unsigned int x,y;
        for(x=0;x<Milli_Sec;x++)
	{
                for(y=0;y<180;y++)
		{
                          if(Front_IR == 1)
			{
                                                L_Motor_Data1 = 0;
				L_Motor_Data2 = 0;
				R_Motor_Data1 = 0;
				R_Motor_Data2 = 0;
				UART_ST( "OBSTACLE DETECTED" );
				while(1);
  }
             }
                       }
                                 }
				
	

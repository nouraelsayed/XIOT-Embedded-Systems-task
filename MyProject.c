                //Directives
#define   used_outputport_status  TRISD
#define   used_inputport_status   TRISB
#define   used_port_initital_val  PORTD
#define   input_pin               RB0_bit
#define   output_pin              RD3_bit
#define   pull_up                  0
#define   pull_down                1
#define   ADC_pin                  0

int count = 92 ;   //counter for interrupt each 3 sec
int  i    = 0 ;

//Functions prototype
void serial_monitor (char * text[]);  //sending data to UART
void IO_control (void);               // LED ON State
void temp_sensor (void);              //Measuring Temp
void Interrupt(void);                 //ISR with (external interrupt)


 //Main program
void main(void)
{
  
  used_inputport_status   = 0x01;
  used_outputport_status  = 0x00;
  INTCON                  = 0XA0;
  OPTION_REG              =0X87;
  TMR0                    =0;

    do
      { } while(1);
}



void serial_monitor (char * text[])
{
     UART1_Init(9600);
     UART1_Write_Text(text);
     UART1_Write(13);
     UART1_Write(10);
}


void IO_control (void)
 {
    output_pin = 1;
    serial_monitor ("pressed!!!")  ;
    serial_monitor ("LED ON")  ;
 }
 
 
void temp_sensor (void)
  {    
      int temp =0;      //initial condition
      char txt [8];
      temp=adc_read(ADC_pin ) * 0.4887586;    // digitalval=value on pin o of adc 5*1000/1204
      intToStr(temp, txt);
      serial_monitor (txt)  ;
      serial_monitor ("is the Room Temp in °C")  ;
  }
  
  
void Interrupt()
{

     if(INTCON.INTF)   //in case the external interrupt is enabled
     {
       IO_control ();
       INTCON.INTF = 0;     //disable interrupt
     }

      if (TMR0IF_bit)    //  in case the timer0 interrupt is enabled
        {   
             i++  ;
            TMR0IF_bit   = 0;
            TMR0         = 0;  }

      if (i==count)
      {
         temp_sensor() ;
         i=0 ;

      }
}
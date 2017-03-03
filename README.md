"# NU411_MP34DT02" 

NUCLEO 411 (LQFP64)+ Ampak Sensor Board with wifi module:GB9662(spi mode)


Sensor     pin name     board connectors        Target MCU IO
LPS25HB/ST 
           I2C_SCL      CN5/SCL/D15             PB8
           I2C_SDA      CN5/SDA/D14             PB9
           INT_DRDY     CN5/D8                  PA9
		   
BH1730FVC/ROHM    
           I2C_SCL      CN5/SCL/D15             PB8
           I2C_SDA      CN5/SDA/D14             PB9
		   
LSM6DS33/ST    
           I2C_SCL      CN5/SCL/D15             PB8
           I2C_SDA      CN5/SDA/D14             PB9
           INT2         CN10/Pin34              PC4
           INT1         CN9/D2                  PA10
		   
HTS221/ST    
           I2C_SCL      CN5/SCL/D15             PB8
           I2C_SDA      CN5/SDA/D14             PB9
		   
LSM303AGR/ST    
           I2C_SCL      CN5/SCL/D15             PB8
           I2C_SDA      CN5/SDA/D14             PB9
           INT_1_XL     CN9/D3                  PB3
           INT_2_XL     CN9/D4                  PB5
           INT_MAG/DRDY CN9/D7                  PA8
		   
TCRT5000/VISHAY    
           C2           CN8/A0                  PA0
		   
UVIS25/ST    
          I2C_SCL       CN5/SCL/D15             PB8
          I2C_SDA       CN5/SDA/D14             PB9
          INT_DRDY      CN10/Pin6               PC5
		  
MP34DT02/ST
        DOUT            CN7/Pin37               PC3                                   
        LR              CN10/Pin16              PB12      (don't connect)
        CLK             J24/Pin2 (remove R71)                                       
		                                        PA1        TIM2_CHOUT    
                        CN10/Pin30              PB13       I2S_CK        
                        CN7/Pin17               PA15       TIM2_CHIN      
						
        I2S   2MHz          1MHz 
	    clk  -----> TIM/2  -----> MP34DT02 CLK
        sd   <------------------- MP34DT02 DOUT
						
AMPAK WIFI SIP GB9662 
        SPI_MISO        CN5/D12                 PA6
        SPI_SCK         CN5/D13                 PA5
        SPI_MOSI        CN5/D11                 PA7
        SPI_IRQ         CN5/D9                  PC7
        SPI_CS          CN5/D10                 PB6
        WL_HOST_WAKE    CN9/D6                  PB10
        WL_REG_ON       CN9/D5                  PB4
		
External SPI-Flash
        SPI3_MISO       CN7/pin2                PC11
        SPI3_MOSI       CN7/Pin3                PC12
        SPI3_SCK        CN7/Pin1                PC10
        SPI3_CS         CN10/Pin22              PB2
		
USB Device type A
        DP              CN10/Pin12              PA12
        DM              CN10/Pin14              PA11	
		
        *USB feature need HSE xtal

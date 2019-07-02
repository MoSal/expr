#include <stdio.h>
#include <stdlib.h>

int main() {
	char *freq0_s, *freq1_s, *freq2_s, *freq3_s, *freq4_s, *freq5_s, *freq6_s, *freq7_s;
	FILE *freq0_f, *freq1_f, *freq2_f, *freq3_f, *freq4_f, *freq5_f, *freq6_f, *freq7_f;
	int freq0, freq1, freq2, freq3, freq4, freq5, freq6, freq7;

	char  *temp0_s,  *temp1_s;
	FILE  *temp0_f,  *temp1_f;
	int temp0, temp1;

	freq0_s=(char *)calloc(64,sizeof(char));
	freq1_s=(char *)calloc(64,sizeof(char));
	freq2_s=(char *)calloc(64,sizeof(char));
	freq3_s=(char *)calloc(64,sizeof(char));
	freq4_s=(char *)calloc(64,sizeof(char));
	freq5_s=(char *)calloc(64,sizeof(char));
	freq6_s=(char *)calloc(64,sizeof(char));
	freq7_s=(char *)calloc(64,sizeof(char));

  if ((freq0_f=fopen("/sys/devices/system/cpu/cpu0/cpufreq/scaling_cur_freq","r")) == NULL) return 1;
  if ((freq1_f=fopen("/sys/devices/system/cpu/cpu1/cpufreq/scaling_cur_freq","r")) == NULL) return 1;
  if ((freq2_f=fopen("/sys/devices/system/cpu/cpu2/cpufreq/scaling_cur_freq","r")) == NULL) return 1;
  if ((freq3_f=fopen("/sys/devices/system/cpu/cpu3/cpufreq/scaling_cur_freq","r")) == NULL) return 1;
  if ((freq4_f=fopen("/sys/devices/system/cpu/cpu4/cpufreq/scaling_cur_freq","r")) == NULL) return 1;
  if ((freq5_f=fopen("/sys/devices/system/cpu/cpu5/cpufreq/scaling_cur_freq","r")) == NULL) return 1;
  if ((freq6_f=fopen("/sys/devices/system/cpu/cpu6/cpufreq/scaling_cur_freq","r")) == NULL) return 1;
  if ((freq7_f=fopen("/sys/devices/system/cpu/cpu7/cpufreq/scaling_cur_freq","r")) == NULL) return 1;

  fgets(freq0_s, 63, freq0_f);
  fgets(freq1_s, 63, freq1_f);
  fgets(freq2_s, 63, freq2_f);
  fgets(freq3_s, 63, freq3_f);
  fgets(freq4_s, 63, freq4_f);
  fgets(freq5_s, 63, freq5_f);
  fgets(freq6_s, 63, freq6_f);
  fgets(freq7_s, 63, freq7_f);

	freq0=atoi(freq0_s);
	freq1=atoi(freq1_s);
	freq2=atoi(freq2_s);
	freq3=atoi(freq3_s);
	freq4=atoi(freq4_s);
	freq5=atoi(freq5_s);
	freq6=atoi(freq6_s);
	freq7=atoi(freq7_s);

  if ((temp0_f=fopen("/sys/devices/platform/coretemp.0/hwmon/hwmon1/subsystem/hwmon1/temp1_input","r")) == NULL) return 1;
  if ((temp1_f=fopen("/sys/devices/platform/coretemp.0/hwmon/hwmon1/subsystem/hwmon2/temp1_input","r")) == NULL) return 1;


	temp0_s=(char *)calloc(64,sizeof(char));
	temp1_s=(char *)calloc(64,sizeof(char));

  fgets(temp0_s, 63, temp0_f);
  fgets(temp1_s, 63, temp1_f);


	temp0=atoi(temp0_s);
	temp1=atoi(temp1_s);

	fclose(freq0_f);
	fclose(freq1_f);
	fclose(freq2_f);
	fclose(freq3_f);
	fclose(freq4_f);
	fclose(freq5_f);
	fclose(freq6_f);
	fclose(freq7_f);

	fclose(temp0_f);
	fclose(temp1_f);

	free(freq0_s);
	free(freq1_s);
	free(freq2_s);
	free(freq3_s);
	free(freq4_s);
	free(freq5_s);
	free(freq6_s);
	free(freq7_s);

	free(temp0_s);
	free(temp1_s);

	fprintf(stdout,"T:%d,%d fq:%d,%d\n",
      temp0/1000,
      temp1/1000,
      (freq0+freq1+freq2+freq3)/1000/4,
      (freq4+freq5+freq6+freq7)/1000/4
      );
	return 0;
}

int v1,v2,v3,v4;
float P1,P2,P3,P4;

loop(){
	aktifkan_relay(relay_6);
	matikan_relay(relay_5);
	matikan_relay(relay_4);
	matikan_relay(relay_3);
	delay_milidetik(100);
	v1=baca_input(A0);
	P1=hitung_daya1(v1);
	if ( !( (v1<5) && (v1>=0.4) ) ){
		tampilkan(v1,P1);
		
		aktifkan_relay(relay_6);
		aktifkan_relay(relay_5);
		matikan_relay(relay_4);
		matikan_relay(relay_3);
		delay_milidetik(100);
		v2=baca_input(A0);
		P2=hitung_daya2(v2);
		if ( !( (v2<5) && (v2>=0.4) ) ){
			tampilkan(v2,P2);
			
			aktifkan_relay(relay_6);
			aktifkan_relay(relay_5);
			aktifkan_relay(relay_4);
			matikan_relay(relay_3);
			delay_milidetik(100);
			v3=baca_input(A0);
			P3=hitung_daya3(v3);
			if ( !( (v3<5) && (v3>=0.4) ) ){
				tampilkan(v2,P2);
				
				aktifkan_relay(relay_6);
				aktifkan_relay(relay_5);
				aktifkan_relay(relay_4);
				aktifkan_relay(relay_3);
				delay_milidetik(100);
				v4=baca_input(A0);
				P4=hitung_daya4(v4);
				if ( !( (v4<5) && (v4>=0.4) ) ){
					tampilkan_pesan_its_bad();
					matikan_semua_relay();
				}
				else{
					tampilkan(v4,P4);
				}
				
			}
			else{
				tampilkan(v3,P3);
			}
			
		}
		else{
			tampilkan(v2,P2);
		}
		
	}
	else{
		tampilkan(v1,P1);

	}
}

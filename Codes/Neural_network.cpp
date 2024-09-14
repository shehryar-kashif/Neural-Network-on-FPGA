#include<iostream>
#include<math.h>

using namespace std;

const int HEIGHT = 1024;
const int WIDTH = 680;
const int size_iter = 10240;

//for hidden layer
float sigmoid(float inp) {
	return (1.0 / (1.0 + exp(-inp)));
}

void forward_propogation(int input_image[size_iter][3], float output_image[size_iter][2]) {
	int input_layer[4] = {};
	float hidden_layer[8] = {};
	float output_layer[2] = {};
	float weights[44] = { 4.5491951900495442, -0.27780114515170723, 0.828799712396735, 0.45408111669002565, 6.5228982096626185,
		4.3638768228039586, -4.2163737468365827, 1.0121887549969142, 6.9655683475483512, -5.2548847251157165, 2.4494556705037618,
		0.61260884352158418, -0.23979759796187697, 3.3458086461887868, -3.5266983398486942, -1.127912690238779, 3.2782935358229537,
		-2.7586191156232105, 2.6106685116490982, 0.052197506218571436, 8.2743163579647323, 5.0835390908886247, -5.5252131743590613,
		1.2443684275085367, 7.0985825242620084, -2.2380683081066413, 0.76505867113094261, 0.46478550264234508, 0.025274536768547764,
		-2.8043910744463538, 0.98355530218305454, -1.2017804559568439, 1.129296434753585, -4.0913462077225926, -0.24175647395779123,
		1.876508523299995, -0.46796606412382891, 0.61222316640745, -2.9704458052411549, 1.5588990248285317, -1.2700604701224847,
		0.41614767660981328, -1.962908380332234, 1.8299713760532905 };
	
	for (int pixel = 0; pixel < size_iter; pixel++) {
#pragma HLS UNROLL factor=2
		int weight_count = 0;
		input_layer[0] = input_image[pixel][0];
		input_layer[1] = input_image[pixel][1];
		input_layer[2] = input_image[pixel][2];
		input_layer[3] = 1.0;
		for (int neuron = 0; neuron < 7; neuron++) {
#pragma HLS UNROLL factor=7
			hidden_layer[neuron] = (input_layer[0] * weights[weight_count++] + input_layer[1] * weights[weight_count++] + input_layer[2] * weights[weight_count++] + input_layer[3] * weights[weight_count++]);
			hidden_layer[neuron] = sigmoid(hidden_layer[neuron]);
		}
		hidden_layer[7] = 1.0;
		for (int neuron = 0; neuron < 2; neuron++) {
#pragma HLS UNROLL factor=2
			output_layer[neuron] = (hidden_layer[0] * weights[weight_count++] + hidden_layer[1] * weights[weight_count++] + hidden_layer[2] * weights[weight_count++] + hidden_layer[3] * weights[weight_count++]
				+ hidden_layer[4] * weights[weight_count++] + hidden_layer[5] * weights[weight_count++] + hidden_layer[6] * weights[weight_count++] + hidden_layer[7] * weights[weight_count++]);
			output_image[pixel][neuron] = sigmoid(output_layer[neuron]);
		}
	}
}

void nn_start(int input[size_iter][3], float output[size_iter][2]) {
#pragma HLS INTERFACE axis register both port=input
#pragma HLS INTERFACE axis register both port=output
	forward_propogation(input, output);
}

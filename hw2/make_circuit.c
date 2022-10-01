/* make_circuit.c
 * This file contains code to make an OR gate out of transistors.
 * Your assignment is to replace it with code that makes a full adder 
 * out of transistors.
 */
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#include "transistors.h"

// Citation Sources : https://www.youtube.com/watch?v=LycHE-Ldj6I

// input_a, input_b, and output are wires

// make a cout_bar & sum_bar that converts the input using XOR function to get the output
void cout_and_sum_bar(circuit *c, int input_wire_a, int input_wire_b, int input_cin_wire, int sum_bar_wire, int cout_bar_wire)
{
	// get a one node

	int one = new_node(c, ONE);

	// get a zero node

	int zero = new_node(c, ZERO);

	// get twelve P and N transistors
	int p1 = new_node(c, P);
	int p2 = new_node(c, P);
	int p3 = new_node(c, P);
	int p4 = new_node(c, P);
	int p5 = new_node(c, P);
	int p6 = new_node(c, P);
	int p7 = new_node(c, P);
	int p8 = new_node(c, P);
	int p9 = new_node(c, P);
	int p10 = new_node(c, P);
	int p11 = new_node(c, P);
	int p12 = new_node(c, P);
	int n1 = new_node(c, N);
	int n2 = new_node(c, N);
	int n3 = new_node(c, N);
	int n4 = new_node(c, N);
	int n5 = new_node(c, N);
	int n6 = new_node(c, N);
	int n7 = new_node(c, N);
	int n8 = new_node(c, N);
	int n9 = new_node(c, N);
	int n10 = new_node(c, N);
	int n11 = new_node(c, N);
	int n12 = new_node(c, N);

	// wire 0: links zero as an output and the sources N1, N3 and N4 as the input
	int wire0 = new_wire(c);
	attach_node_to_wire(c, zero, wire0, OUTPUT);
	attach_node_to_wire(c, n1, wire0, INPUT);
	attach_node_to_wire(c, n3, wire0, INPUT);
	attach_node_to_wire(c, n4, wire0, INPUT);

	// wire 1: links the output of source N1 to the input of source N2
	int wire1 = new_wire(c);
	attach_node_to_wire(c, n1, wire1, OUTPUT);
	attach_node_to_wire(c, n2, wire1, INPUT);

	// wire 2: links the output of the sources N3 and N4 to the input of source N5
	int wire2 = new_wire(c);
	attach_node_to_wire(c, n3, wire2, OUTPUT);
	attach_node_to_wire(c, n4, wire2, OUTPUT);
	attach_node_to_wire(c, n5, wire2, INPUT);

	// links input a to the gates P2, P4, N2, and N3
	attach_node_to_wire(c, p2, input_wire_a, CONTROL);
	attach_node_to_wire(c, p4, input_wire_a, CONTROL);
	attach_node_to_wire(c, n2, input_wire_a, CONTROL);
	attach_node_to_wire(c, n3, input_wire_a, CONTROL);

	// links input b to the gates P3, P5, N1, and N4
	attach_node_to_wire(c, p3, input_wire_b, CONTROL);
	attach_node_to_wire(c, p5, input_wire_b, CONTROL);
	attach_node_to_wire(c, n1, input_wire_b, CONTROL);
	attach_node_to_wire(c, n4, input_wire_b, CONTROL);

	// links input cin to the gates P1 and N5
	attach_node_to_wire(c, p1, input_cin_wire, CONTROL);
	attach_node_to_wire(c, n5, input_cin_wire, CONTROL);

	// wire 3: links the output of one to the input of sources P1 and P2
	int wire3 = new_wire(c);
	attach_node_to_wire(c, one, wire3, OUTPUT);
	attach_node_to_wire(c, p1, wire3, INPUT);
	attach_node_to_wire(c, p2, wire3, INPUT);

	// wire 4: links the output of source P2 to the input of source P3
	int wire4 = new_wire(c);
	attach_node_to_wire(c, p2, wire4, OUTPUT);
	attach_node_to_wire(c, p3, wire4, INPUT);

	// wire 5: links the output of sources P1 and P3 to the input of sources P4 and P5
	int wire5 = new_wire(c);
	attach_node_to_wire(c, p1, wire5, OUTPUT);
	attach_node_to_wire(c, p3, wire5, OUTPUT);
	attach_node_to_wire(c, p4, wire5, INPUT);
	attach_node_to_wire(c, p5, wire5, INPUT);

	// link drains P4, P5, N2 and N5 to the cout_bar_wire
	attach_node_to_wire(c, p4, cout_bar_wire, OUTPUT);
	attach_node_to_wire(c, p5, cout_bar_wire, OUTPUT);
	attach_node_to_wire(c, n2, cout_bar_wire, OUTPUT);
	attach_node_to_wire(c, n5, cout_bar_wire, OUTPUT);

	/*
	/ this is the start of sum_bar transistors
	*/

	// wire 6: links the output of zero_2 to the input of N6, N10, N11, N12
	int wire6 = new_wire(c);
	attach_node_to_wire(c, zero, wire6, OUTPUT);
	attach_node_to_wire(c, n6, wire6, INPUT);
	attach_node_to_wire(c, n10, wire6, INPUT);
	attach_node_to_wire(c, n11, wire6, INPUT);
	attach_node_to_wire(c, n12, wire6, INPUT);

	// wire 7: links the ouput of source N6 to the input of source N7
	int wire7 = new_wire(c);
	attach_node_to_wire(c, n6, wire7, OUTPUT);
	attach_node_to_wire(c, n7, wire7, INPUT);

	// wire 8: links the output of source N7 to the input of source N8
	int wire8 = new_wire(c);
	attach_node_to_wire(c, n7, wire8, OUTPUT);
	attach_node_to_wire(c, n8, wire8, INPUT);

	// wire 9: links the output of sources N10, N11 and N12 to the input of source N9
	int wire9 = new_wire(c);
	attach_node_to_wire(c, n10, wire9, OUTPUT);
	attach_node_to_wire(c, n11, wire9, OUTPUT);
	attach_node_to_wire(c, n12, wire9, OUTPUT);
	attach_node_to_wire(c, n9, wire9, INPUT);

	// links input a to the gates of N5, N10, P6, and P10
	attach_node_to_wire(c, n8, input_wire_a, CONTROL);
	attach_node_to_wire(c, n10, input_wire_a, CONTROL);
	attach_node_to_wire(c, p6, input_wire_a, CONTROL);
	attach_node_to_wire(c, p10, input_wire_a, CONTROL);

	// links input b to the gates of N7, N11, P7, and P11
	attach_node_to_wire(c, n7, input_wire_b, CONTROL);
	attach_node_to_wire(c, n11, input_wire_b, CONTROL);
	attach_node_to_wire(c, p7, input_wire_b, CONTROL);
	attach_node_to_wire(c, p11, input_wire_b, CONTROL);

	// links input cin to the gates N6, N12, P8, and P12
	attach_node_to_wire(c, n6, input_cin_wire, CONTROL);
	attach_node_to_wire(c, n12, input_cin_wire, CONTROL);
	attach_node_to_wire(c, p8, input_cin_wire, CONTROL);
	attach_node_to_wire(c, p12, input_cin_wire, CONTROL);

	// links input cout_bar_wire to the gates N9 and P9
	attach_node_to_wire(c, n9, cout_bar_wire, CONTROL);
	attach_node_to_wire(c, p9, cout_bar_wire, CONTROL);

	// wire 10: links the output of one_2 to the input of sources P6, P7 and P8
	int wire10 = new_wire(c);
	attach_node_to_wire(c, one, wire10, OUTPUT);
	attach_node_to_wire(c, p6, wire10, INPUT);
	attach_node_to_wire(c, p7, wire10, INPUT);
	attach_node_to_wire(c, p8, wire10, INPUT);

	// wire 11: links the output of sources P6, P7 and P8 to the input of sources P9 and P10
	int wire11 = new_wire(c);
	attach_node_to_wire(c, p6, wire11, OUTPUT);
	attach_node_to_wire(c, p7, wire11, OUTPUT);
	attach_node_to_wire(c, p8, wire11, OUTPUT);
	attach_node_to_wire(c, p9, wire11, INPUT);
	attach_node_to_wire(c, p10, wire11, INPUT);

	// wire 12: links the output of souce P10 to the input of source P11
	int wire12 = new_wire(c);
	attach_node_to_wire(c, p10, wire12, OUTPUT);
	attach_node_to_wire(c, p11, wire12, INPUT);

	// wire 13: links the output of source P11 to the input of source P12
	int wire13 = new_wire(c);
	attach_node_to_wire(c, p11, wire13, OUTPUT);
	attach_node_to_wire(c, p12, wire13, INPUT);

	// link drains N8, N9, P9 and P12 to the sum_bar_wire output
	attach_node_to_wire(c, n8, sum_bar_wire, OUTPUT);
	attach_node_to_wire(c, n9, sum_bar_wire, OUTPUT);
	attach_node_to_wire(c, p9, sum_bar_wire, OUTPUT);
	attach_node_to_wire(c, p12, sum_bar_wire, OUTPUT);
}

// make an inverter that puts the NXOR of the signal from the input wire
// onto the output wire

void make_inverter(circuit *c, int input_wire, int output_wire)
{
	int p, n, one, zero, wire0, wire1;

	// get P and N transistors

	p = new_node(c, P);
	n = new_node(c, N);

	// get a one and a zero

	one = new_node(c, ONE);
	zero = new_node(c, ZERO);

	// make a couple of wires

	wire0 = new_wire(c);
	wire1 = new_wire(c);

	// connect input wire to gates of p and n

	attach_node_to_wire(c, p, input_wire, CONTROL);
	attach_node_to_wire(c, n, input_wire, CONTROL);

	// attach zero to source of N

	attach_node_to_wire(c, zero, wire0, OUTPUT);
	attach_node_to_wire(c, n, wire0, INPUT);

	// attach one to source of P

	attach_node_to_wire(c, one, wire1, OUTPUT);
	attach_node_to_wire(c, p, wire1, INPUT);

	// attach drain of P and N to output

	attach_node_to_wire(c, p, output_wire, OUTPUT);
	attach_node_to_wire(c, n, output_wire, OUTPUT);
}

void cout_and_sum(circuit *c, int input_wire_a, int input_wire_b, int input_cin_wire, int sum_wire, int cout_wire)
{

	// get 2 wires

	int connect_wire = new_wire(c);
	int connect_wire_2 = new_wire(c);

	// get the NXOR of the inputs onto that wire

	cout_and_sum_bar(c, input_wire_a, input_wire_b, input_cin_wire, connect_wire, connect_wire_2);

	// hook up the output of the NXOR to the input of the inverters,
	// and put the output of the inverters on our output

	make_inverter(c, connect_wire, sum_wire);
	make_inverter(c, connect_wire_2, cout_wire);
}

void make_circuit(circuit *c)
{
	// three input nodes for the circuit

	int input_a = new_node(c, INPUT_NODE);
	int input_b = new_node(c, INPUT_NODE);
	int input_cin = new_node(c, INPUT_NODE);

	// three wires to connect to the inputs

	int input_wire_a = new_wire(c);
	int input_wire_b = new_wire(c);
	int input_cin_wire = new_wire(c);
	attach_node_to_wire(c, input_a, input_wire_a, OUTPUT);
	attach_node_to_wire(c, input_b, input_wire_b, OUTPUT);
	attach_node_to_wire(c, input_cin, input_cin_wire, OUTPUT);

	// two output node for the circuit

	int output = new_node(c, OUTPUT_NODE);
	int output_2 = new_node(c, OUTPUT_NODE);

	// two wires for the output

	int cout_wire = new_wire(c);
	int sum_wire = new_wire(c);
	attach_node_to_wire(c, output, sum_wire, INPUT);
	attach_node_to_wire(c, output_2, cout_wire, INPUT);

	// make an XOR print the inputs and putting the result on the console
	// output wire

	cout_and_sum(c, input_wire_a, input_wire_b, input_cin_wire, sum_wire, cout_wire);
}

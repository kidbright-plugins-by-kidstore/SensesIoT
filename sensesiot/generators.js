const SensesIoT_BEGIN_WORD = 'DEV_IO.SensesIoT()';

Blockly.JavaScript['senses_config'] = function(block) {
	var value_userid = Blockly.JavaScript.valueToCode(block, 'userid', Blockly.JavaScript.ORDER_ATOMIC) || "0";
	var value_key = Blockly.JavaScript.valueToCode(block, 'key', Blockly.JavaScript.ORDER_ATOMIC) || "";
	var code = `${SensesIoT_BEGIN_WORD}.config(${value_userid}, ${value_key});\n`;
	return code;
};

Blockly.JavaScript['senses_send'] = function(block) {
	var value_data = Blockly.JavaScript.valueToCode(block, 'data', Blockly.JavaScript.ORDER_ATOMIC) || "0";
	var value_slot = Blockly.JavaScript.valueToCode(block, 'slot', Blockly.JavaScript.ORDER_ATOMIC) || "0";
	var code = `${SensesIoT_BEGIN_WORD}.send(${value_slot}, ${value_data});\n`;
	return code;
};

Blockly.JavaScript['senses_get_digital_control'] = function(block) {
	var value_port = Blockly.JavaScript.valueToCode(block, 'port', Blockly.JavaScript.ORDER_ATOMIC) || "0";
	var code = `${SensesIoT_BEGIN_WORD}.getDigitalControl(${value_port})`;
	return [code, Blockly.JavaScript.ORDER_NONE];
};

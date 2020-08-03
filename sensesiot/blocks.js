Blockly.Blocks['senses_config'] = {
	init: function () {
		this.jsonInit({
			"type": "senses_config",
			"message0": Blockly.Msg.SENSESIOT_CONFIG_MESSAGE,
			"args0": [
			  {
				"type": "input_value",
				"name": "userid",
				"check": "Number"
			  },
			  {
				"type": "input_value",
				"name": "key",
				"check": "String"
			  }
			],
			"inputsInline": true,
			"previousStatement": null,
			"nextStatement": null,
			"colour": 90,
			"tooltip": Blockly.Msg.SENSESIOT_CONFIG_TOOLTIP,
			"helpUrl": "https://www.sensesiot.com/"
		  });
	},
	xmlToolbox: function() {
		return `
		<block type="senses_config">
		  	<value name="userid">
				<shadow type="math_number">
					<field name="VALUE">0</field>
				</shadow>
			</value>
			<value name="key">
				<shadow type="basic_string">
				<field name="VALUE">--device-key--</field></shadow>
			</value>
		</block>
		`;
	}
};

Blockly.Blocks['senses_send'] = {
	init: function () {
		this.jsonInit({
			"type": "senses_send",
			"message0": Blockly.Msg.SENSESIOT_SEND_MESSAGE,
			"args0": [
			  {
				"type": "input_value",
				"name": "data",
				"check": [
					"Boolean",
					"Number"
				]
			  },
			  {
				"type": "input_value",
				"name": "slot",
				"check": "Number"
			  }
			],
			"inputsInline": true,
			"previousStatement": null,
			"nextStatement": null,
			"colour": 90,
			"tooltip": Blockly.Msg.SENSESIOT_SEND_TOOLTIP,
			"helpUrl": "https://www.sensesiot.com/"
		  });
	},
	xmlToolbox: function() {
		return `
		<block type="senses_send">
		  	<value name="data">
				<shadow type="math_number">
					<field name="VALUE">0</field>
				</shadow>
			</value>
			<value name="slot">
				<shadow type="math_number">
					<field name="VALUE">1</field>
				</shadow>
			</value>
		</block>
		`;
	}
};

Blockly.Blocks['senses_get_digital_control'] = {
	init: function () {
		this.jsonInit({
			"type": "senses_get_digital_control",
			"message0": Blockly.Msg.SENSESIOT_GET_DIGITAL_CONTROL_MESSAGE,
			"args0": [
			  {
				"type": "input_value",
				"name": "port",
				"check": "Number"
			  }
			],
			"inputsInline": true,
			"output": [
			  "Boolean",
			  "Number"
			],
			"colour": 90,
			"tooltip": Blockly.Msg.SENSESIOT_GET_DIGITAL_CONTROL_TOOLTIP,
			"helpUrl": "https://www.sensesiot.com/"
		});
	},
	xmlToolbox: function() {
		return `
		<block type="senses_get_digital_control">
		  	<value name="port">
				<shadow type="math_number">
					<field name="VALUE">1</field>
				</shadow>
			</value>
		</block>
		`;
	}
};

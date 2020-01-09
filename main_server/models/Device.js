const mongoose = require("mongoose");
var User = require("./User");

const DeviceSchema = new mongoose.Schema({
	name : {
		type : String,
		required : true
	},
	os : {
		type : String,
		required : true
	},
	ipAddress : {
		type : String
	},
	port : {
		type : String
	},
	loginStatus : { 
		type : Boolean,
	},
	userId : {
		type : mongoose.Schema.Types.ObjectId,
		ref : User
	},
	joinDate : {
		type : Date,
		default : Date.now
	},
	modifiedDate : {
		type : Date,
		default : Date.now
	}
});




module.exports = mongoose.model("Device", DeviceSchema, "devices");
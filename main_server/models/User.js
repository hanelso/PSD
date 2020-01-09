const mongoose = require("mongoose");

const UserSchema = new mongoose.Schema({
	id : {
		type : String,
		unique : true,
		lowercase : true,
		required : [true, "userId must have value"]
	},
	password : {
		type : String,
		required : [true, "userPwd must have value"],
		trim : true
	},
	nickname : String,
	permission : {
		type : Number,
		required : true
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

UserSchema.statics.join = function(joinInfo, finalcallback)
{
	var user = new this(joinInfo);
	return user.save()
};

UserSchema.methods.login = function(loginInfo, finalcallback)
{

}

module.exports = mongoose.model("User", UserSchema, "users");



//https://www.zerocho.com/category/MongoDB/post/59a1870210b942001853e250
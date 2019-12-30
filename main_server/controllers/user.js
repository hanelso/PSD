var bcrypt = require("bcrypt");


function UserController() {

}

UserController.join = function(req, res, callback)
{
	res.userId = testid;
	res.userPwd = testpwd;
	res.status(200).send({ msg : "SUCCES"});
};


UserController.login = function(req, res, callback)
{
	res.status(200).send({ msg : "SUCCESS"});
	/*
	if(err) res.send(err);
	else
	{
		if(req.body.password != "testpwd") res.status(400).send({msg : "PASSWORD_NOT_MATCHED"});
		else
		{
			res.status(200).send({ msg : "SUCCESS"});
		}
	}
	*/
};


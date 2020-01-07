var bcrypt = require("bcrypt");
var User = require("../models/User");

function UserController() {

}

UserController.join = function(req, res, next){
	User.join(req.body)
    .then(user => res.send(user))
    .catch(err => res.status(500).send(err));
};


module.exports = UserController;
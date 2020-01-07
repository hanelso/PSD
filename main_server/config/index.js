var config = {
	env : "development",
	ip : "http://localhost:",
	PORT : 3000,
	db : {
		id : "psd_admin",
		pwd : "psdadminpwd",
		name : "psd_db"
	}
};

config.db.uri = "mongodb://" + config.db.id + ":" + config.db.pwd + "@127.0.0.1:27017/admin"

module.exports = config;

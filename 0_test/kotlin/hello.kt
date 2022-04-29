fun addProduct(desc: String? = null, name: String, price: Double = 0.0) =
	"Adding prouduct with $name, ${desc ?: "None"}, and $price"

fun main() {
	println("${addProduct("Desc", "Name", 5.0)}");
	println("${addProduct(name = "Name", price = 5.0)}");
	println("${addProduct(name = "Name")}");
}

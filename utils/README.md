# Huh Language - `util` Module

The `util` module in the Huh programming language provides a collection of essential utility functions that simplify common operations. These utilities are designed to improve developer productivity and streamline common programming tasks, such as string manipulation, collection handling, and basic mathematical operations. Below is a detailed description of the available functions in the `util` module:

## Installation

To use the `util` module in Huh, simply import it into your project:

```huh
import util;
```

## Available Functions

### 1. `util.map(collection, func)`
Applies a function to each element in a collection and returns a new collection with the results.

**Parameters:**
- `collection`: An array or list to iterate over.
- `func`: A function to apply to each element.

**Example:**
```huh
let result = util.map([1, 2, 3], (x) => x * 2);
// result = [2, 4, 6]
```

### 2. `util.filter(collection, predicate)`
Filters elements in a collection based on a predicate function and returns a new collection of elements that satisfy the condition.

**Parameters:**
- `collection`: The collection to filter.
- `predicate`: A function that returns `true` or `false`.

**Example:**
```huh
let result = util.filter([1, 2, 3, 4], (x) => x % 2 == 0);
// result = [2, 4]
```

### 3. `util.reduce(collection, func, initial)`
Reduces a collection to a single value by applying a reducer function to each element, accumulating the result.

**Parameters:**
- `collection`: The collection to reduce.
- `func`: The reducer function that takes two arguments: the accumulator and the current value.
- `initial`: The initial value of the accumulator.

**Example:**
```huh
let sum = util.reduce([1, 2, 3, 4], (acc, x) => acc + x, 0);
// sum = 10
```

### 4. `util.random(min, max)`
Generates a random integer between `min` and `max` (inclusive).

**Parameters:**
- `min`: The minimum value (inclusive).
- `max`: The maximum value (inclusive).

**Example:**
```huh
let randNum = util.random(1, 100);
```

### 5. `util.capitalize(string)`
Capitalizes the first letter of a given string and returns the new string.

**Parameters:**
- `string`: The string to capitalize.

**Example:**
```huh
let result = util.capitalize("huh language");
// result = "Huh language"
```

### 6. `util.flatten(collection)`
Flattens a nested collection into a single-level array.

**Parameters:**
- `collection`: A nested array or list.

**Example:**
```huh
let flat = util.flatten([[1, 2], [3, 4], [5]]);
// flat = [1, 2, 3, 4, 5]
```

### 7. `util.isEmpty(collection)`
Checks if a collection is empty and returns `true` if it contains no elements, otherwise `false`.

**Parameters:**
- `collection`: The collection to check.

**Example:**
```huh
let emptyCheck = util.isEmpty([]);
// emptyCheck = true
```

### 8. `util.unique(collection)`
Removes duplicate values from a collection and returns an array of unique elements.

**Parameters:**
- `collection`: An array or list.

**Example:**
```huh
let uniqueValues = util.unique([1, 2, 2, 3, 4, 4]);
// uniqueValues = [1, 2, 3, 4]
```

### 9. `util.range(start, end, step)`
Generates an array of numbers within a specified range, starting from `start`, up to `end`, with an optional `step`.

**Parameters:**
- `start`: The starting value.
- `end`: The ending value (exclusive).
- `step`: The difference between each number (optional, default is 1).

**Example:**
```huh
let numbers = util.range(1, 10, 2);
// numbers = [1, 3, 5, 7, 9]
```

## License
This `util` module is open-source and available under the MIT License. Contributions are welcome.

--- 

This README covers the basic functionality of the `util` module. More advanced use cases and optimizations can be explored by diving into the module's source code and documentation.

Happy coding!
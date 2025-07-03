#include <stdio.h>
#include <json-c/json.h>

int main() {
    const char *json_string = "{\"name\": \"John Doe\", \"age\": 30, \"isStudent\": false}";
    
    // Parse the JSON string into a json_object
    struct json_object *parsed_json = json_tokener_parse(json_string);
    if (parsed_json == NULL) {
        fprintf(stderr, "Error parsing JSON string\n");
        return 1;
    }

    // Get the values from the object
    struct json_object *name_obj;
    struct json_object *age_obj;

    if (json_object_object_get_ex(parsed_json, "name", &name_obj) &&
        json_object_object_get_ex(parsed_json, "age", &age_obj)) {
        
        // Extract the values from the JSON objects
        const char *name = json_object_get_string(name_obj);
        int age = json_object_get_int(age_obj);

        printf("Name: %s\n", name);
        printf("Age: %d\n", age);
    } else {
        printf("Could not find 'name' or 'age' in JSON object.\n");
    }

    // Free the memory allocated for the parsed JSON object
    json_object_put(parsed_json);

    return 0;
}
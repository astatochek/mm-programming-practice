package com.example.swaggerdemo;

import io.swagger.v3.oas.annotations.media.Schema;
import lombok.Getter;
import lombok.Setter;

@Getter
@Setter
@Schema(name = "Contact", description = "A contact in the repository", requiredProperties = {"id", "name"})
public class Contact {

    @Schema(description = "Contact ID", example = "1")
    private String id;

    @Schema(description = "Contact name", example = "John Doe")
    private String name;

    @Schema(description = "Contact phone", example = "123-456-789")
    private String phone;
}

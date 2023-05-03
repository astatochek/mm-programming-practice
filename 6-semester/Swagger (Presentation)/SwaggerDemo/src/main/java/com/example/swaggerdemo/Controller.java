package com.example.swaggerdemo;

import io.swagger.v3.oas.annotations.Hidden;
import io.swagger.v3.oas.annotations.Operation;
import io.swagger.v3.oas.annotations.Parameter;
import io.swagger.v3.oas.annotations.enums.ParameterIn;
import io.swagger.v3.oas.annotations.media.Content;
import io.swagger.v3.oas.annotations.media.Schema;
import io.swagger.v3.oas.annotations.responses.ApiResponse;
import io.swagger.v3.oas.annotations.responses.ApiResponses;
import io.swagger.v3.oas.annotations.servers.Server;
import io.swagger.v3.oas.annotations.tags.Tag;
import io.swagger.v3.oas.annotations.tags.Tags;
import org.springframework.web.bind.annotation.*;

import java.util.ArrayList;
import java.util.List;
import java.util.concurrent.ConcurrentHashMap;
import java.util.concurrent.ConcurrentMap;

@RestController
public class Controller {
    ConcurrentMap<String, Contact> contacts = new ConcurrentHashMap<>();

    @Tags({
            @Tag(name = "contacts", description = "Operations related to contacts")
    })
    @Operation(summary = "Get a contact by id",
            description = "Returns a single contact",
            parameters = { @Parameter(in = ParameterIn.PATH,
                    name = "id",
                    required = true,
                    description = "Is the identification of the contact",
                    schema = @Schema(type = "string",
                            example = "1")) })
    @ApiResponses(value = {
            @ApiResponse(responseCode = "200", description = "Found the contact",
                    content = { @Content(mediaType = "application/json",
                            schema = @Schema(implementation = Contact.class)) }),
            @ApiResponse(responseCode = "400", description = "Invalid id supplied",
                    content = @Content),
            @ApiResponse(responseCode = "404", description = "Contact not found",
                    content = @Content) })
    @GetMapping("/{id}")
    public Contact getContact(@PathVariable String id) {
        return contacts.get(id);
    }

    @Tags({
            @Tag(name = "contacts", description = "Operations related to contacts")
    })
    @GetMapping("/")
    public List<Contact> getAllContacts() {
        return new ArrayList<>(contacts.values());
    }

    @Tags({
            @Tag(name = "contacts", description = "Operations related to contacts")
    })
    @PostMapping("/")
    public Contact addContact(@RequestBody Contact contact) {
        contacts.put(contact.getId(), contact);
        return contact;
    }

    @Hidden
    @GetMapping("/secret")
    public String secretEndpoint() {
        // implementation here
        return "";
    }

    @Tags({
            @Tag(name = "not contacts", description = "Operations not related to contacts")
    })
    @Deprecated
    @GetMapping("/old")
    public String oldEndpoint() {
        // implementation here
        return "";
    }


}

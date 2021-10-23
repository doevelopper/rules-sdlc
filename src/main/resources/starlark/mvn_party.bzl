load("@rules_jvm_external//:defs.bzl", "maven_install")
load("@rules_jvm_external//:specs.bzl", "maven", "parse")

def dependency(coordinates, exclusions = None):
    artifact = parse.parse_maven_coordinate(coordinates)
    return maven.artifact(
        group = artifact["group"],
        artifact = artifact["artifact"],
        packaging = artifact.get("packaging"),
        classifier = artifact.get("classifier"),
        version = artifact["version"],
        exclusions = exclusions,
    )

deps = [
    dependency("org.apache.maven.archetype:archetype-common:2.2"),
    dependency("org.apache.maven.archetype:archetype-descriptor:2.2"),
    dependency("org.apache.maven.archetype:archetype-registry:2.2"),
    dependency("org.apache.maven:maven-artifact:3.5.4"),
    dependency("org.apache.maven:maven-artifact-manager:2.2.1"),
    dependency("org.apache.maven:maven-builder-support:3.5.4"),
    dependency("org.apache.maven:maven-core:3.5.4"),
    dependency("org.apache.maven:maven-model:3.5.4"),
    dependency("org.apache.maven:maven-model-builder:3.5.4"),
    dependency("org.apache.maven:maven-plugin-api:3.5.4"),
    dependency("org.apache.maven:maven-plugin-registry:2.2.1"),
    dependency("org.apache.maven:maven-profile:2.2.1"),
    dependency("org.apache.maven:maven-project:2.2.1"),
    dependency("org.apache.maven:maven-repository-metadata:3.5.4"),
    dependency("org.apache.maven:maven-resolver-provider:3.5.4"),
    dependency("org.apache.maven:maven-settings:3.5.4"),
    dependency("org.apache.maven:maven-settings-builder:3.5.4"),
    dependency("org.apache.maven.resolver:maven-resolver-api:1.3.3"),
    dependency("org.apache.maven.resolver:maven-resolver-connector-basic:1.3.1"),
    dependency("org.apache.maven.resolver:maven-resolver-impl:1.3.3"),
    dependency("org.apache.maven.resolver:maven-resolver-spi:1.3.3"),
    dependency("org.apache.maven.resolver:maven-resolver-transport-file:1.3.1"),
    dependency("org.apache.maven.resolver:maven-resolver-transport-http:1.3.1"),
    dependency("org.apache.maven.resolver:maven-resolver-util:1.3.1"),
    dependency("org.apache.maven.shared:maven-common-artifact-filters:1.4"),
    dependency("org.apache.maven.shared:maven-invoker:2.0.11"),
    dependency("org.apache.maven.shared:maven-shared-utils:3.2.1"),
    dependency("org.apache.maven.wagon:wagon-provider-api:1.0-beta-6"),
    dependency("log4j:log4j:1.2.17"),
    dependency("junit:junit:4.12", exclusions = ["org.hamcrest:hamcrest-core"]),
    dependency("velocity:velocity:1.5"),
]

def mvn_dependencies():
    maven_install(
        artifacts = deps,
        repositories = [
            "https://repo.maven.apache.org/maven2/",
            "https://mvnrepository.com/artifact",
            "https://maven-central.storage.googleapis.com",
            "http://gitblit.github.io/gitblit-maven",
        ],
        generate_compat_repositories = True,
        # bazel 'run @maven//:pin' to acquire this json file
        maven_install_json = "//:maven_install.json",
    )

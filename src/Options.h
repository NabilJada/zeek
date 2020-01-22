// See the file "COPYING" in the main distribution directory for copyright.

#pragma once

#include <optional>
#include <string>
#include <vector>

#include "DNS_Mgr.h"

namespace zeek {

/**
 * Options that define general Zeek processing behavior, usually determined
 * from command-line arguments.
 */
struct Options {
	/**
	 * Unset options that aren't meant to be used by the supervisor, but may
	 * make sense for supervised nodes to inherit (as opposed to flagging
	 * as an error an exiting outright if used in supervisor-mode).
	 */
	void filter_supervisor_options();

	/**
	 * Inherit certain options set in the original supervisor parent process
	 * and discard the rest.
	 */
	void filter_supervised_node_options();

	bool print_version = false;
	bool print_usage = false;
	bool print_execution_time = false;
	bool print_signature_debug_info = false;
	int print_plugins = 0;

	std::optional<std::string> debug_log_streams;
	std::optional<std::string> debug_script_tracing_file;

	std::optional<std::string> identifier_to_print;
	std::optional<std::string> script_code_to_exec;
	std::vector<std::string> script_prefixes = { "" }; // "" = "no prefix"

	int signature_re_level = 4;
	bool ignore_checksums = false;
	bool use_watchdog = false;
	double pseudo_realtime = 0;
	DNS_MgrMode dns_mode = DNS_DEFAULT;

	bool supervisor_mode = false;
	bool parse_only = false;
	bool bare_mode = false;
	bool debug_scripts = false;
	bool perftools_check_leaks = false;
	bool perftools_profile = false;

	bool run_unit_tests = false;
	std::vector<std::string> doctest_args;

	std::optional<std::string> pcap_filter;
	std::vector<std::string> interfaces;
	std::vector<std::string> pcap_files;
	std::vector<std::string> signature_files;

	std::optional<std::string> pcap_output_file;
	std::optional<std::string> random_seed_input_file;
	std::optional<std::string> random_seed_output_file;
	std::optional<std::string> process_status_file;
	std::optional<std::string> zeekygen_config_file;
	std::string libidmef_dtd_file = "idmef-message.dtd";

	std::set<std::string> plugins_to_load;
	std::vector<std::string> scripts_to_load;
	std::vector<std::string> script_options_to_set;
};

} // namespace zeek
